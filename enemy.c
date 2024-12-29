/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:15:59 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/29 17:16:00 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_data(t_data *data)
{
	data->enemy.down_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/ennemies/zombie_down_ground.xpm", &data->tiles.size,
			&data->tiles.size);
	data->enemy.down_data = (int *)mlx_get_data_addr(data->enemy.down_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.up_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/ennemies/zombie_up_ground.xpm", &data->tiles.size,
			&data->tiles.size);
	data->enemy.up_data = (int *)mlx_get_data_addr(data->enemy.up_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.right_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/ennemies/zombie_right_ground.xpm", &data->tiles.size,
			&data->tiles.size);
	data->enemy.right_data = (int *)mlx_get_data_addr(data->enemy.right_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.left_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/ennemies/zombie_left_ground.xpm", &data->tiles.size,
			&data->tiles.size);
	data->enemy.left_data = (int *)mlx_get_data_addr(data->enemy.left_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
  data->enemy.dir = 'D';
}
