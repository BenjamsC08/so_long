/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:17:29 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 23:25:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	base_map_img(t_data *data)
{
	data->map.img_ptr = mlx_new_image(data->mlx, data->width_win,
			data->height_win);
	data->map.img_data = (int *)mlx_get_data_addr(data->map.img_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.wall_ptr = mlx_xpm_file_to_image(data->mlx,
			WALL_IMG, &data->tiles.size, &data->tiles.size);
	data->tiles.wall_data = (int *)mlx_get_data_addr(data->tiles.wall_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.coll_ptr = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE_IMG, &data->tiles.size, &data->tiles.size);
	data->tiles.coll_data = (int *)mlx_get_data_addr(data->tiles.coll_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.door_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			DOOR_CLOSE_IMG, &data->tiles.size, &data->tiles.size);
	data->tiles.door_data[0] = (int *)mlx_get_data_addr(data->tiles.door_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.door_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			DOOR_OPEN_IMG, &data->tiles.size, &data->tiles.size);
	data->tiles.door_data[1] = (int *)mlx_get_data_addr(data->tiles.door_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static int	alloc_map_img_ptr_data(t_data *data)
{
	data->tiles.ground_ptr = (void **)malloc(sizeof(void *) * 4);
	if (!data->tiles.ground_ptr)
		return (0);
	data->tiles.ground_data = (int **)malloc(sizeof(int *) * 4);
	if (!data->tiles.ground_data)
		return (free(data->tiles.ground_ptr), 0);
	return (1);
}

static int	ground_img(t_data *data)
{
	if (! alloc_map_img_ptr_data(data))
		return (0);
	data->tiles.ground_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			GROUND_IMG_1, &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data[0] = (int *)mlx_get_data_addr(
			data->tiles.ground_ptr[0], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	data->tiles.ground_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			GROUND_IMG_2, &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data[1] = (int *)mlx_get_data_addr(
			data->tiles.ground_ptr[1], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	data->tiles.ground_ptr[2] = mlx_xpm_file_to_image(data->mlx,
			GROUND_IMG_3, &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data[2] = (int *)mlx_get_data_addr(
			data->tiles.ground_ptr[2], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	data->tiles.ground_ptr[3] = mlx_xpm_file_to_image(data->mlx,
			GROUND_IMG_4, &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data[3] = (int *)mlx_get_data_addr(
			data->tiles.ground_ptr[3], &data->map.bpp, &data->map.line_len,
			&data->map.endian);
	return (1);
}

static int	overlay_img(t_data *data)
{
	int	x;
	int	y;

	x = WIDTH_OVL;
	y = HEIGHT_OVL;
	data->map.asset_ptr = (void **)malloc(sizeof(void *) * 3);
	if (!data->map.asset_ptr)
		return (0);
	data->map.asset_data = (int **)malloc(sizeof(int *) * 3);
	if (!data->map.asset_data)
		return (try_to_free_overlay(data), 0);
	data->map.asset_ptr[0] = mlx_xpm_file_to_image(data->mlx,
			OVERLAY_BACKGROUND, &y, &x);
	data->map.asset_data[0] = (int *)mlx_get_data_addr(data->map.asset_ptr[0],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->map.asset_ptr[1] = mlx_xpm_file_to_image(data->mlx,
			OVERLAY_STEP_BANNER, &y, &x);
	data->map.asset_data[1] = (int *)mlx_get_data_addr(data->map.asset_ptr[1],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->map.asset_ptr[2] = mlx_xpm_file_to_image(data->mlx,
			OVERLAY_COLL_BANNER, &y, &x);
	data->map.asset_data[2] = (int *)mlx_get_data_addr(data->map.asset_ptr[2],
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	return (1);
}

void	map_data(t_data *data)
{
	if (!ground_img(data))
		classic_close(data);
	base_map_img(data);
	if (!overlay_img(data))
		close_all(data);
}
