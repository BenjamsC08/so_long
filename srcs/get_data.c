/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:13:11 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 14:19:03 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	win_data(t_data *data)
{
	data->tiles.size = TILE_SIZE;
	data->map.y_max = count_lines(data->path);
	data->enemy.is_on = 0;
	data->map.bp = get_map(data, &data->map.x_max);
	if (!data->map.bp)
	{
		classic_close(data);
		return ;
	}
	if (data->map.y_max > MAX_Y_WIN)
	{
		if (data->map.x_max > MAX_X_WIN)
			data->map.win = extract_bp_to_win(data, 3);
		else
			data->map.win = extract_bp_to_win(data, 1);
	}
	else if (data->map.x_max > MAX_X_WIN)
		data->map.win = extract_bp_to_win(data, 2);
	else
	{
		data->width_win = data->map.x_max * TILE_SIZE;
		data->height_win = (data->map.y_max + EXTRA_HEIGHT) * TILE_SIZE;
		data->map.win = data->map.bp;
		data->map.resize = 0;
	}
}

static void	map_data(t_data *data)
{
	data->map.img_ptr = mlx_new_image(data->mlx, data->width_win,
			data->height_win);
	data->map.img_data = (int *)mlx_get_data_addr(data->map.img_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.wall_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/map/wall.xpm", &data->tiles.size, &data->tiles.size);
	data->tiles.wall_data = (int *)mlx_get_data_addr(data->tiles.wall_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.ground_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/map/ground.xpm", &data->tiles.size, &data->tiles.size);
	data->tiles.ground_data = (int *)mlx_get_data_addr(data->tiles.ground_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.door_o_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/map/door_open.xpm", &data->tiles.size,
			&data->tiles.size);
	data->tiles.door_o_data = (int *)mlx_get_data_addr(data->tiles.door_o_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->tiles.door_c_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/map/door_close.xpm", &data->tiles.size,
			&data->tiles.size);
	data->tiles.door_c_data = (int *)mlx_get_data_addr(data->tiles.door_c_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

static void	player_data(t_data *data)
{
	data->perso.down_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_down.xpm", &data->tiles.size,
			&data->tiles.size);
	data->perso.down_data = (int *)mlx_get_data_addr(data->perso.down_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.up_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_up.xpm", &data->tiles.size,
			&data->tiles.size);
	data->perso.up_data = (int *)mlx_get_data_addr(data->perso.up_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.right_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_right.xpm", &data->tiles.size,
			&data->tiles.size);
	data->perso.right_data = (int *)mlx_get_data_addr(data->perso.right_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.left_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_left.xpm", &data->tiles.size,
			&data->tiles.size);
	data->perso.left_data = (int *)mlx_get_data_addr(data->perso.left_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.dir = 'D';
	data->perso.step = 0;
	data->perso.nb_collectible = 0;
}

static void	other_data(t_data *data)
{
	int	x;
	int	y;

	x = WIDTH_OVL;
	y = HEIGHT_OVL;
	data->tiles.coll_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible/bag.xpm", &data->tiles.size,
			&data->tiles.size);
	data->tiles.coll_data = (int *)mlx_get_data_addr(data->tiles.coll_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->map.asset_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/other/datav1.xpm", &x, &y);
	data->map.asset_data = (int *)mlx_get_data_addr(data->map.asset_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

int	load_data(t_data *data)
{
	win_data(data);
	if (!data->map.bp)
		return (0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width_win,
			data->height_win, "so_long");
	if (!data->win)
		return (0);
	map_data(data);
	player_data(data);
	other_data(data);
	if (data->enemy.is_on == 1)
		enemy_data(data);
	return (1);
}
