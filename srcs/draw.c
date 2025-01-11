/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:56:11 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 23:40:32 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_c_pixel(t_data *data, int big_pixel, int small_pixel, int *pos)
{
	int	*tiles_data;

	tiles_data = NULL;
	if (data->map.win[pos[0]][pos[1]] == '1')
		tiles_data = data->tiles.wall_data;
	else if (data->map.win[pos[0]][pos[1]] == 'P')
	{
		data->perso.y = pos[0];
		data->perso.x = pos[1];
		tiles_data = get_player_img_data(data);
	}
	else if (data->map.win[pos[0]][pos[1]] == 'C')
		tiles_data = data->tiles.coll_data;
	else if (data->map.win[pos[0]][pos[1]] == 'E'
			&& data->perso.nb_collectible == data->collectibles)
		tiles_data = data->tiles.door_data[1];
	else if (data->map.win[pos[0]][pos[1]] == 'E'
			&& data->perso.nb_collectible != data->collectibles)
		tiles_data = data->tiles.door_data[0];
	else if (data->map.win[pos[0]][pos[1]] == 'Z')
		tiles_data = get_enemy_img_data(data, pos[0], pos[1]);
	else
		tiles_data = get_map_img_data(data, pos);
	if (tiles_data != NULL)
		data->map.img_data[big_pixel] = tiles_data[small_pixel];
}

void	draw_map(t_data *data, int *big_pixel, int *small_pixel)
{
	int	pos[2];
	int	i;
	int	j;

	pos[0] = -1;
	while (++pos[0] < (data->height_win >> 5) - EXTRA_HEIGHT)
	{
		pos[1] = -1;
		while (++pos[1] < (data->width_win >> 5))
		{
			j = -1;
			while (++j < data->tiles.size)
			{
				i = -1;
				while (++i < data->tiles.size)
				{
					*big_pixel = (pos[0] * data->tiles.size + j)
						* (data->width_win)
						+ (pos[1] * data->tiles.size + i);
					*small_pixel = j * data->tiles.size + i;
					put_c_pixel(data, *big_pixel, *small_pixel, pos);
				}
			}
		}
	}
}

void	draw_strs(t_data *data)
{
	char		*str;
	int			colors_coll;

	if (data->perso.moove_count == 0)
		str = "0";
	else
		str = ft_itoa(data->perso.moove_count);
	mlx_string_put(data->mlx, data->win, (data->width_win / 10) + 40,
		((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE) + 34),
		encode_trgb(255, 0, 0, 0), str);
	if (str && data->perso.moove_count != 0)
		free(str);
	if (data->perso.nb_collectible == 0)
		str = "0";
	else
		str = ft_itoa(data->perso.nb_collectible);
	colors_coll = encode_trgb(255, 255, 0, 0);
	if (is_ok(data))
		colors_coll = encode_trgb(255, 38, 119, 1);
	mlx_string_put(data->mlx, data->win,
		(data->width_win / 2 + data->width_win / 14) + 10,
		((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE) + 34),
		colors_coll, str);
	if (data->perso.nb_collectible != 0 && str)
		free(str);
	str = NULL;
}

void	draw_overlay(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->map.asset_ptr[0],
		0, ((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE)));
	mlx_put_image_to_window(data->mlx, data->win, data->map.asset_ptr[1],
		data->width_win / 10, ((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE) + 16));
	mlx_put_image_to_window(data->mlx, data->win, data->map.asset_ptr[2],
		data->width_win / 2 + data->width_win / 14,
		((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE) + 16));
}
