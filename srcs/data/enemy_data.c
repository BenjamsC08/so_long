/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:14:48 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 15:17:58 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_img(t_data *data)
{
	data->enemy.down_ptr = mlx_xpm_file_to_image(data->mlx,
			ENEMY_DOWN_1, &data->tiles.size, &data->tiles.size);
	data->enemy.down_data = (int *)mlx_get_data_addr(data->enemy.down_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.up_ptr = mlx_xpm_file_to_image(data->mlx,
			ENEMY_UP_1, &data->tiles.size, &data->tiles.size);
	data->enemy.up_data = (int *)mlx_get_data_addr(data->enemy.up_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.right_ptr = mlx_xpm_file_to_image(data->mlx,
			ENEMY_RIGHT_1, &data->tiles.size, &data->tiles.size);
	data->enemy.right_data = (int *)mlx_get_data_addr(data->enemy.right_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.left_ptr = mlx_xpm_file_to_image(data->mlx,
			ENEMY_LEFT_1, &data->tiles.size, &data->tiles.size);
	data->enemy.left_data = (int *)mlx_get_data_addr(data->enemy.left_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

void	enemy_data(t_data *data)
{
	enemy_img(data);
	data->enemy.dir = 'D';
}
