/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:54:19 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/27 00:49:42 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_management_map(int err_code, char *path_map)
{
	if (err_code == -1)
		ft_printf("The map is not rectangular\ncheck : %s\n", path_map);
	if (err_code == -2 || err_code == -3)
		ft_printf("The map is not closed\ncheck : %s\n", path_map);
	if (err_code == -4)
		ft_printf("The map have not allowed char,\n\
allowed char : 01PECZ\ncheck : %s\n", path_map);
	if (err_code == -5)
		ft_printf("The map need only one P and E, \
and need at least one C\ncheck : %s\n", path_map);
	if (err_code == -6)
		ft_printf("The map file need to have .ber extension\ncheck : %s\n",
			path_map);
	if (err_code == -7)
		ft_printf("The map is not doable\ncheck : %s\n", path_map);
	if (err_code == -8)
		ft_printf("Dup map failed\ncheck : %s\n", path_map);
	return ;
}
