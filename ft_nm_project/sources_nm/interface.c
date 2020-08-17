/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:16:47 by rchallie          #+#    #+#             */
/*   Updated: 2020/08/17 19:14:13 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_nm/ft_nm.h"

/*
** interface_print_filename:
** -------------
**		Print a file name using a format.
**
**		params:	"filename" the file name.
*/

void	interface_print_filename(
	char *filename
)
{
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(filename, 1);
	ft_putstr_fd(" :\n", 1);
}
