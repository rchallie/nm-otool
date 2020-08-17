/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:32:46 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/17 18:55:47 by rchallie         ###   ########.fr       */
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
	int			file_desc;
	size_t		file_size;
	void		*map;
}				t_memmap;

/*
** Memory Map
*/

int				memmap(char *path, struct s_memmap *memmap);

/*
** Error
*/

int				error(int errnum);

/*
** Interface
*/

void			interface_print_filename(char *filename);

#endif
