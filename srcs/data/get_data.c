/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:13:11 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 22:29:19 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	bp_parse(t_data *data)
{
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
	bp_parse(data);
}

int	load_data(t_data *data)
{
	data->map.win = NULL;
	win_data(data);
	if (!data->map.bp)
		return (0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (classic_close(data), 0);
	data->win = mlx_new_window(data->mlx, data->width_win,
			data->height_win, "so_long");
	if (!data->win)
		return (in_run_free(data), 0);
	if (!map_data(data))
		return (in_run_free(data), 0);
	if (!player_data(data))
		return (in_run_free(data), 0);
	if (data->enemy.is_on == 1)
  {
		if (!enemy_data(data))
      return (in_run_free(data), 0);
  }
	data->enemy.idling = 0;
	return (1);
}
