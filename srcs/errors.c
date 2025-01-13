/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:54:19 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 22:31:10 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_management_map(int err_code, char *path_map)
{
	if (err_code == -1)
		ft_printf("Error\nThe map is not rectangular check : %s\n", path_map);
	if (err_code == -2 || err_code == -3)
		ft_printf("Error\nThe map is not closed\ncheck : %s\n", path_map);
	if (err_code == -4)
		ft_printf("Error\nThe map have not allowed char,\n\
allowed char : 01PECZ\ncheck : %s\n", path_map);
	if (err_code == -5)
		ft_printf("Error\nThe map need only one P and E, \
and need at least one C (you can also add a Z)\ncheck : %s\n", path_map);
	if (err_code == -6)
		ft_printf("Error\nThe map file need to have .ber extension\ncheck : %s\n",
			path_map);
	if (err_code == -7)
		ft_printf("Error\nThe map is not doable\ncheck : %s\n", path_map);
	if (err_code == -8)
		ft_printf("Error\nDup map failed\ncheck : %s\n", path_map);
	return ;
}
