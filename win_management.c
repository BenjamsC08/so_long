/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:45:51 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/27 01:27:05 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_data *data)
{
	int		big_p;
	int		small_p;

	if (keycode == ESC)
		close_all(data);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		moove(data, keycode);
	if (keycode == U_ARROW || keycode == L_ARROW
		|| keycode == R_ARROW || keycode == D_ARROW)
		moove(data, keycode);
	draw_map(data, &big_p, &small_p);
	mlx_put_image_to_window(data->mlx, data->win, data->map.img_ptr,
		0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map.asset_ptr,
		0, ((data->height_win) - (EXTRA_HEIGHT * TILE_SIZE)));
	draw_strs(data);
	ft_printf("%d\n", data->perso.moove_count);
	return (0);
}

int	create_window(char *path_map)
{
	t_data		data;
	int			big_p;
	int			small_p;

	big_p = 0;
	small_p = 0;
	data.path = ft_strdup(path_map);
	if (!load_data(&data))
		return (0);
	draw_map(&data, &big_p, &small_p);
	mlx_put_image_to_window(data.mlx, data.win, data.map.img_ptr, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.map.asset_ptr,
		0, ((data.height_win) - (EXTRA_HEIGHT * TILE_SIZE)));
	data.perso.moove_count = 0;
	draw_strs(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 0, close_all, &data);
	mlx_loop(data.mlx);
	return (0);
}
