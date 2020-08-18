/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:41:34 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/18 22:42:26 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_nm/ft_nm.h"

/*
** error:
** -------------
**		Function called when an problem  appear
**		in the program. See included header for
**		errors list.
**
**		params:	"errnum" the error number.
**
**		return:	-1.
*/

int	error(
	int errnum
)
{
	if (errnum == ERROR_OPEN_FILE)
		ft_putstr_fd("An error appeared while opening the file.\n", 2);
	else if (errnum == ERROR_STAT_FILE)
		ft_putstr_fd("An error appeared while getting the file informations.\n"
		, 2);
	else if (errnum == ERROR_MMAP_MAPPING)
		ft_putstr_fd("File can't be mapped.\n", 2);
	else if (errnum == ERROR_INVALID_FORMAT)
		ft_putstr_fd("Invalid file format.\n", 2);
	else if (errnum == ERROR_FIND_SYMTAB)
		ft_putstr_fd("File has no symtab.\n", 2);
	return (ERROR);
}
