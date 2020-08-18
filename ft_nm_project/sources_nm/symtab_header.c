/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtab_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:35:52 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/18 23:11:22 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_nm/ft_nm.h"

/*
** info_range_int:
** -------------
**		Give an unsigned int x64 which contains
**		informations on "range_size" bytes from
**		"start_range" after the beginning of the
**		memory map.
**
**		params:	"memmap"		the structure of memory map.
**				"range_start"	the address of the information.
**				"range_size"	number of bytes of the information.
**
**		return:	the information in u_int64_t.
*/

static u_int64_t info_range_int(
	struct s_memmap memmap,
	unsigned int range_start,
	size_t range_size
)
{
	u_int64_t info;
	u_int8_t *cursor;
	
	cursor = &memmap.map[range_start + range_size - 1];
	info = *cursor;
	while (--cursor != &memmap.map[range_start - 1])
		info = *(cursor) + info * 0x100;
	return (info);
}

static void     section_header_informations(
	struct s_memmap memmap,
	struct s_secheader *secheader
)
{
	u_int64_t hstrtab_index;
	
	*secheader = (struct s_secheader){};
	hstrtab_index = info_range_int(memmap, 0x3E, 2);
	secheader->offset = info_range_int(memmap, ADDR_SEC_HEADER_OFFSET, 8);
	secheader->header_size = info_range_int(memmap, ADDR_SEC_HEADER_SIZE, 2);
	secheader->numb_header = info_range_int(memmap, ADDR_SEC_HEADER_NUMB, 2);
	secheader->hstrtab_offset = info_range_int(memmap, 
									secheader->offset + (secheader->header_size
									* hstrtab_index) + 0x18, 8);
}

static void     header(
	struct s_memmap memmap,
	struct s_header *header,
	u_int64_t start_addr
)
{
	*header = (struct s_header){};
	header->offset = info_range_int(memmap, start_addr + 0x18, 8);
	header->size = info_range_int(memmap, start_addr + 0x20, 8);
}

int      symbol_table_header(
	struct s_memmap memmap,
	struct s_header *symtab
)
{
	t_secheader	secheader;

	*symtab = (t_header){.offset = -1, .size = -1};
	section_header_informations(memmap, &secheader);
	while (secheader.numb_header - 1 != 0)
	{
		if (!(ft_strncmp(".symtab",
				memmap.map + secheader.hstrtab_offset
				+ info_range_int(memmap,
				secheader.offset + ((secheader.numb_header - 1)
				* secheader.header_size), 4), ft_strlen(".symtab"))))
			header(memmap, symtab, secheader.offset 
				+ ((secheader.numb_header - 1) * secheader.header_size));
		secheader.numb_header--;
	}
	return ((symtab->offset == (u_int64_t)-1
		|| symtab->size == (u_int64_t)-1) ? ERROR : SUCCESS);
}
