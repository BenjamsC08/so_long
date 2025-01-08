/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:13:11 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 11:18:12 by benjamsc         ###   ########.fr       */
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

static void	other_data(t_data *data)
{
	int	x;
	int	y;

	x = WIDTH_OVL;
	y = HEIGHT_OVL;
	data->tiles.coll_ptr = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE_IMG, &data->tiles.size,
			&data->tiles.size);
	data->tiles.coll_data = (int *)mlx_get_data_addr(data->tiles.coll_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->map.asset_ptr = mlx_xpm_file_to_image(data->mlx,
			"./textures/other/datav2.xpm", &x, &y);
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
