/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:14:48 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/11 21:25:34 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_malloc(t_data *data)
{
	data->enemy.ptr = (void **)malloc(sizeof(void *) * 8);
	if (!data->enemy.ptr)
		return (0);
	data->enemy.data = (int **)malloc(sizeof(int *) * 8);
	if (!data->enemy.data)
		return (try_to_free_enemy(data), 0);
	return (1);
}

static void	enemy_img_y(t_data *data)
{
	data->enemy.ptr[0] = mlx_xpm_file_to_image(data->mlx, ENEMY_DOWN_1,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[0] = (int *)mlx_get_data_addr(data->enemy.ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[1] = mlx_xpm_file_to_image(data->mlx, ENEMY_DOWN_2,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[1] = (int *)mlx_get_data_addr(data->enemy.ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[2] = mlx_xpm_file_to_image(data->mlx, ENEMY_UP_1,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[2] = (int *)mlx_get_data_addr(data->enemy.ptr[2],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[3] = mlx_xpm_file_to_image(data->mlx, ENEMY_UP_2,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[3] = (int *)mlx_get_data_addr(data->enemy.ptr[3],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static void	enemy_img_x(t_data *data)
{
	data->enemy.ptr[4] = mlx_xpm_file_to_image(data->mlx, ENEMY_RIGHT_1,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[4] = (int *)mlx_get_data_addr(data->enemy.ptr[4],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[5] = mlx_xpm_file_to_image(data->mlx, ENEMY_RIGHT_2,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[5] = (int *)mlx_get_data_addr(data->enemy.ptr[5],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[6] = mlx_xpm_file_to_image(data->mlx, ENEMY_LEFT_1,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[6] = (int *)mlx_get_data_addr(data->enemy.ptr[6],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.ptr[7] = mlx_xpm_file_to_image(data->mlx, ENEMY_LEFT_2,
			&data->tiles.size, &data->tiles.size);
	data->enemy.data[7] = (int *)mlx_get_data_addr(data->enemy.ptr[7],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

int	enemy_data(t_data *data)
{
	data->enemy.ptr = NULL;
	data->enemy.data = NULL;
	if (!enemy_malloc(data))
		return (0);
	enemy_img_y(data);
	enemy_img_x(data);
	data->enemy.dir = 'D';
	data->enemy.step = 0;
	return (1);
}
