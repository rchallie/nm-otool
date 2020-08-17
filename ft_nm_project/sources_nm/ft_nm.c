/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:31:34 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/17 19:02:07 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// http://www.skyfree.org/linux/references/ELF_Format.pdf
// https://wiki.tcl-lang.org/page/ELF

#include "../includes_nm/ft_nm.h"

static void nm_close(struct s_memmap *memmap)
{
	close(memmap->file_desc);
	munmap(memmap->map, memmap->file_size);
}

static int  nm_protocol(char *path)
{
	int func_return;
	t_memmap mem_map;
	
	func_return = 0;
	mem_map = (t_memmap) {};
	interface_print_filename(path);
	if ((func_return = memmap(path, &mem_map)) != SUCCESS)
			return (func_return);
	nm_close(&mem_map);
	return (func_return);
}

static int  nm_multiple(int argc, char **argv)
{
	int i;
	int func_return;

	i = 1;
	func_return = 0;
	while (i < argc)
		if (nm_protocol(argv[i++]) != SUCCESS)
			func_return += 1;
	return (func_return);
}

static int  nm_default(void)
{
	return ((nm_protocol("a.out") != SUCCESS) ? 1 : 0);
}

int         main(int argc, char **argv)
{
	if (argc >= 2)
		return (nm_multiple(argc, argv));
	else
		return (nm_default());
	return (0);
}
