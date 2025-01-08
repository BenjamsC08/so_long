/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:17:29 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	base_map_img(t_data *data)
{
	data->tiles.wall_ptr = mlx_xpm_file_to_image(data->mlx,
			WALL_IMG, &data->tiles.size, &data->tiles.size);
	data->tiles.wall_data = (int *)mlx_get_data_addr(data->tiles.wall_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.ground_ptr = mlx_xpm_file_to_image(data->mlx,
			GROUND_IMG_1, &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data = (int *)mlx_get_data_addr(data->tiles.ground_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static void object_map_img(t_data *data)
{
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

static void	overlay_img(t_data *data)
{
	int	x;
	int	y;

	x = WIDTH_OVL;
	y = HEIGHT_OVL;
	data->map.asset_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/other/datav2.xpm", &x, &y);
	data->map.asset_data = (int *)mlx_get_data_addr(data->map.asset_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

void	map_data(t_data *data)
{
	data->map.img_ptr = mlx_new_image(data->mlx, data->width_win,
			data->height_win);
	data->map.img_data = (int *)mlx_get_data_addr(data->map.img_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	base_map_img(data);
	object_map_img(data);
	overlay_img(data);
}
