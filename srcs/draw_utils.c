/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:56:52 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 22:28:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_player_img_data(t_data *data)
{
	int	*tiles_data;
	int	k;

	k = data->enemy.idling;
	tiles_data = NULL;
	if (data->perso.dir == 'R')
		tiles_data = data->perso.right_data[k];
	if (data->perso.dir == 'L')
		tiles_data = data->perso.left_data[k];
	if (data->perso.dir == 'U')
		tiles_data = data->perso.up_data[k];
	if (data->perso.dir == 'D')
		tiles_data = data->perso.down_data[k];
	return (tiles_data);
}

int	*get_enemy_img_data(t_data *data, int y, int x)
{
	int	*tiles_data;
	int	k;

	k = data->enemy.idling;
	tiles_data = NULL;
	if (data->enemy.dir == 'R')
		tiles_data = data->enemy.data[4 + k];
	if (data->enemy.dir == 'L')
		tiles_data = data->enemy.data[6 + k];
	if (data->enemy.dir == 'U')
		tiles_data = data->enemy.data[2 + k];
	if (data->enemy.dir == 'D')
		tiles_data = data->enemy.data[0 + k];
	data->enemy.y = y;
	data->enemy.x = x;
	return (tiles_data);
}

int	*get_map_img_data(t_data *data, int *pos)
{
	const int y_max = data->map.y_max;
	const int x_max = data->map.x_max;
	if ( y_max > 7 && y_max <= 17 && x_max > 6 && x_max <= 25)
	{
		if (pos[0] % 4 == 0 && pos[1] % 3 == 0)
			return (data->tiles.ground_data[2]);
		else if (pos[0] == 8 && pos[1] == 8)
			return (data->tiles.ground_data[1]);
		else if (pos[0] % 2 == 0 && pos[1] % 5 == 0)
			return (data->tiles.ground_data[3]);

	}
	return (data->tiles.ground_data[0]);
}
