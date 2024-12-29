/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:56:11 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/29 17:17:09 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*get_player_img_data(t_data *data)
{
	int	*tiles_data;

	tiles_data = NULL;
	if (data->perso.dir == 'R')
		tiles_data = data->perso.right_data;
	if (data->perso.dir == 'L')
		tiles_data = data->perso.left_data;
	if (data->perso.dir == 'U')
		tiles_data = data->perso.up_data;
	if (data->perso.dir == 'D')
		tiles_data = data->perso.down_data;
	return (tiles_data);
}

static int	*get_enemy_img_data(t_data *data, int y, int x)
{
	int	*tiles_data;

	tiles_data = NULL;
	if (data->enemy.dir == 'R')
		tiles_data = data->enemy.right_data;
	if (data->enemy.dir == 'L')
		tiles_data = data->enemy.left_data;
	if (data->enemy.dir == 'U')
		tiles_data = data->enemy.up_data;
	if (data->enemy.dir == 'D')
		tiles_data = data->enemy.down_data;
	data->enemy.y = y;
	data->enemy.x = x;
	return (tiles_data);
}

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
		tiles_data = data->tiles.door_o_data;
	else if (data->map.win[pos[0]][pos[1]] == 'E'
			&& data->perso.nb_collectible != data->collectibles)
		tiles_data = data->tiles.door_c_data;
	else if (data->map.win[pos[0]][pos[1]] == 'Z')
		tiles_data = get_enemy_img_data(data, pos[0], pos[1]);
	else
		tiles_data = data->tiles.ground_data;
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
	const int	px_extra = (EXTRA_HEIGHT * TILE_SIZE);

	if (data->perso.moove_count == 0)
		str = "0";
	else
		str = ft_itoa(data->perso.moove_count);
	mlx_string_put(data->mlx, data->win, 15, (data->height_win - px_extra + 25),
		encode_trgb(255, 0, 0, 0), str);
	if (str && data->perso.moove_count != 0)
		free(str);
	if (data->perso.nb_collectible == 0)
		str = "0";
	else
		str = ft_itoa(data->perso.nb_collectible);
	colors_coll = encode_trgb(255, 255, 0, 0);
	if (data->perso.nb_collectible == data->collectibles)
		colors_coll = encode_trgb(255, 58, 200, 11);
	mlx_string_put(data->mlx, data->win, 10 + 60,
		(data->height_win - px_extra + 25),
		colors_coll, str);
	if (data->perso.nb_collectible != 0 && str)
		free(str);
	str = NULL;
}
