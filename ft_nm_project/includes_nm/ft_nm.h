/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:32:46 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/18 22:45:00 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# define LIBFT_PATH "../../libft/libft.h"

# define SUCCESS 0
# define ERROR -1
# define ERROR_OPEN_FILE -2
# define ERROR_STAT_FILE -3
# define ERROR_MMAP_MAPPING -4
# define ERROR_INVALID_FORMAT -5
# define ERROR_FIND_SYMTAB -6

# define ADDR_SEC_HEADER_OFFSET 0x28
# define ADDR_SEC_HEADER_SIZE 0x3A
# define ADDR_SEC_HEADER_NUMB 0x3C

# include LIBFT_PATH

/*
** File
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

/*
** Memory Map
*/

# include <sys/mman.h>

/*
** Struct memmap:
**		A structure that contain a projection
**		in memory map  of  a  file.  It  also
**		contain utils informations about  the
**		file.
*/

typedef struct	s_memmap
{
	u_int64_t	file_desc;
	size_t		file_size;
	void		*map;
}				t_memmap;

typedef struct	s_secheader
{
	u_int64_t	offset;
	u_int64_t	numb_header;
	u_int64_t	header_size;
	u_int64_t	hstrtab_offset;
}				t_secheader;

typedef struct	s_header
{
	u_int64_t	offset;
	u_int64_t	size;
}				t_header;

/*
** Memory Map
*/

int				memory_map(char *path, struct s_memmap *memmap);

/*
** Error
*/

int				error(int errnum);

/*
** Interface
*/

void			interface_print_filename(char *filename);

/*
** Section header
*/

int				symbol_table_header(struct s_memmap memmap,
    			struct s_header *symtab);

#endif
