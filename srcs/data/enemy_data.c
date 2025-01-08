/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:14:48 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 18:00:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_malloc(t_data *data)
{
	data->enemy.down_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->enemy.down_ptr)
		return (0);
	data->enemy.down_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->enemy.down_data)
		return (try_to_free_enemy(data), 0);
	data->enemy.up_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->enemy.up_ptr)
		return (try_to_free_enemy(data), 0);
	data->enemy.up_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->enemy.up_data)
		return (try_to_free_enemy(data), 0);
	data->enemy.right_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->enemy.right_ptr)
		return (0);
	data->enemy.right_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->enemy.right_data)
		return (try_to_free_enemy(data), 0);
	data->enemy.left_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->enemy.left_ptr)
		return (try_to_free_enemy(data), 0);
	data->enemy.left_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->enemy.left_data)
		return (try_to_free_enemy(data), 0);
	return (1);
}

static void	enemy_img_y(t_data *data)
{
	data->enemy.down_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_DOWN_1, &data->tiles.size, &data->tiles.size);
	data->enemy.down_data[0] = (int *)mlx_get_data_addr(data->enemy.down_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.down_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_DOWN_2, &data->tiles.size, &data->tiles.size);
	data->enemy.down_data[1] = (int *)mlx_get_data_addr(data->enemy.down_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.up_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_UP_1, &data->tiles.size, &data->tiles.size);
	data->enemy.up_data[0] = (int *)mlx_get_data_addr(data->enemy.up_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.up_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_UP_2, &data->tiles.size, &data->tiles.size);
	data->enemy.up_data[1] = (int *)mlx_get_data_addr(data->enemy.up_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static void	enemy_img_x(t_data *data)
{
	data->enemy.right_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_RIGHT_1, &data->tiles.size, &data->tiles.size);
	data->enemy.right_data[0] = (int *)mlx_get_data_addr(data->enemy.right_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.right_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_RIGHT_2, &data->tiles.size, &data->tiles.size);
	data->enemy.right_data[1] = (int *)mlx_get_data_addr(data->enemy.right_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.left_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_LEFT_1, &data->tiles.size, &data->tiles.size);
	data->enemy.left_data[0] = (int *)mlx_get_data_addr(data->enemy.left_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->enemy.left_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			ENEMY_LEFT_2, &data->tiles.size, &data->tiles.size);
	data->enemy.left_data[1] = (int *)mlx_get_data_addr(data->enemy.left_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

void	enemy_data(t_data *data)
{
	data->enemy.down_ptr = NULL;
	data->enemy.down_data = NULL;
	data->enemy.up_ptr = NULL;
	data->enemy.up_data = NULL;
	data->enemy.right_ptr = NULL;
	data->enemy.right_data = NULL;
	data->enemy.left_ptr = NULL;
	data->enemy.left_data = NULL;
	enemy_malloc(data);
	enemy_img_y(data);
	enemy_img_x(data);
	data->enemy.dir = 'D';
	data->enemy.step = 0;
}
