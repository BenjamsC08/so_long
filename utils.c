/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 03:33:26 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 05:12:01 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ok(t_data *data)
{
	if (data->perso.nb_collectible == data->collectibles)
		return (1);
	return (0);
}

int	ft_nl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	resize_map(t_data *data, int k)
{
	if (k == 1)
	{
		data->width_win = data->map.x_max * TILE_SIZE;
		data->height_win = (MAX_Y_WIN + EXTRA_HEIGHT) * TILE_SIZE;
	}
	else if (k == 2)
	{
		data->width_win = MAX_X_WIN * TILE_SIZE;
		data->height_win = (data->map.y_max + EXTRA_HEIGHT) * TILE_SIZE;
	}
	else
	{
		data->width_win = MAX_X_WIN * TILE_SIZE;
		data->height_win = (MAX_Y_WIN + EXTRA_HEIGHT) * TILE_SIZE;
	}
	data->type_resize = k;
	data->map.resize = 1;
}
