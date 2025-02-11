/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:14:00 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/11 21:25:21 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	player_malloc(t_data *data)
{
	data->perso.down_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->perso.down_ptr)
		return (0);
	data->perso.down_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->perso.down_data)
		return (try_to_free_player(data), 0);
	data->perso.up_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->perso.up_ptr)
		return (try_to_free_player(data), 0);
	data->perso.up_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->perso.up_data)
		return (try_to_free_player(data), 0);
	data->perso.right_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->perso.right_ptr)
		return (0);
	data->perso.right_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->perso.right_data)
		return (try_to_free_player(data), 0);
	data->perso.left_ptr = (void **)malloc(sizeof(void *) * 2);
	if (!data->perso.left_ptr)
		return (try_to_free_player(data), 0);
	data->perso.left_data = (int **)malloc(sizeof(int *) * 2);
	if (!data->perso.left_data)
		return (try_to_free_player(data), 0);
	return (1);
}

static void	player_img_y(t_data *data)
{
	data->perso.down_ptr[0] = mlx_xpm_file_to_image(data->mlx, PLAYER_DOWN_1,
			&data->tiles.size, &data->tiles.size);
	data->perso.down_data[0] = (int *)mlx_get_data_addr(data->perso.down_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.down_ptr[1] = mlx_xpm_file_to_image(data->mlx, PLAYER_DOWN_2,
			&data->tiles.size, &data->tiles.size);
	data->perso.down_data[1] = (int *)mlx_get_data_addr(data->perso.down_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.up_ptr[0] = mlx_xpm_file_to_image(data->mlx, PLAYER_UP_1,
			&data->tiles.size, &data->tiles.size);
	data->perso.up_data[0] = (int *)mlx_get_data_addr(data->perso.up_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.up_ptr[1] = mlx_xpm_file_to_image(data->mlx, PLAYER_UP_2,
			&data->tiles.size, &data->tiles.size);
	data->perso.up_data[1] = (int *)mlx_get_data_addr(data->perso.up_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static void	player_img_x(t_data *data)
{
	data->perso.right_ptr[0] = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT_1,
			&data->tiles.size, &data->tiles.size);
	data->perso.right_data[0] = (int *)mlx_get_data_addr(
			data->perso.right_ptr[0], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	data->perso.right_ptr[1] = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT_2,
			&data->tiles.size, &data->tiles.size);
	data->perso.right_data[1] = (int *)mlx_get_data_addr(
			data->perso.right_ptr[1], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	data->perso.left_ptr[0] = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT_1,
			&data->tiles.size, &data->tiles.size);
	data->perso.left_data[0] = (int *)mlx_get_data_addr(data->perso.left_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.left_ptr[1] = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT_2,
			&data->tiles.size, &data->tiles.size);
	data->perso.left_data[1] = (int *)mlx_get_data_addr(data->perso.left_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

int	player_data(t_data *data)
{
	data->perso.down_ptr = NULL;
	data->perso.down_data = NULL;
	data->perso.up_ptr = NULL;
	data->perso.up_data = NULL;
	data->perso.right_ptr = NULL;
	data->perso.right_data = NULL;
	data->perso.left_ptr = NULL;
	data->perso.left_data = NULL;
	if (!player_malloc(data))
		return (0);
	player_img_y(data);
	player_img_x(data);
	data->perso.moove_count = 0;
	data->perso.dir = 'D';
	data->perso.step = 0;
	data->perso.nb_collectible = 0;
	return (1);
}
