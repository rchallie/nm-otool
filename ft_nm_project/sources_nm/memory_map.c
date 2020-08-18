/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:24:22 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/18 22:51:18 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_nm/ft_nm.h"

/*
** memmap:
** -------------
**		Fill a structure that contain a file
**		descriptor, a size and a memory  map
**		of the file if no error appear.
**
**		params:	"path" the path to the file.
**				"memmap" the address of the struct
**						 to fill.
**
**		return:	-1 if an error appear, 0 otherwise.
*/

int	memory_map(
	char *path,
	struct s_memmap *memmap
)
{
	struct stat stats;

	*memmap = (struct s_memmap){};
	if ((memmap->file_desc = open(path, O_RDONLY)) == ERROR)
		return (error(ERROR_OPEN_FILE));
	if (fstat(memmap->file_desc, &stats) == ERROR)
		return (error(ERROR_STAT_FILE));
	memmap->file_size = stats.st_size;
	if ((memmap->map = mmap(NULL, memmap->file_size, PROT_READ,
		MAP_PRIVATE, memmap->file_desc, 0)) == MAP_FAILED)
		return (error(ERROR_MMAP_MAPPING));
	if (ft_strncmp(memmap->map, "\x7F" "ELF\2\1\1", 7))
		return (error(ERROR_INVALID_FORMAT));
	return (SUCCESS);
}
