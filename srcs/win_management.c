/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:45:51 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/11 23:19:37 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ending(t_data *data, char to, int *pos)
{
	if (pos)
		free(pos);
	ft_printf("\n-------------------------------------------------------------");
	if (to == 'E')
		ft_printf("\n--------------------------YOU WIN !\
--------------------------");
	if (to == 'Z')
		ft_printf("\n-------------------------YOU LOOSE !\
-------------------------");
	ft_printf("\n-------------------------------------------------------------");
	ft_printf("\nin : %d step\n", data->perso.moove_count);
	close_all(data);
	return (1);
}

static void	draw_all(t_data *data)
{
	int		big_p;
	int		small_p;

	big_p = 0;
	small_p = 0;
	draw_map(data, &big_p, &small_p);
	mlx_put_image_to_window(data->mlx, data->win, data->map.img_ptr,
		0, 0);
	draw_overlay(data);
	draw_strs(data);
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_all(data);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == S_KEY)
		moove(data, keycode);
	if (keycode == U_ARROW || keycode == L_ARROW
		|| keycode == R_ARROW || keycode == D_ARROW)
		moove(data, keycode);
	if (data->enemy.is_on == 1)
		enemy_moove(data);
	draw_all(data);
	ft_printf("%d\n", data->perso.moove_count);
	return (0);
}

static int	idling_hook(t_data *data)
{
	static int	frame_counter = 0;

	frame_counter++;
	if (frame_counter % 10000 == 0)
	{
		if (data->enemy.idling == 0)
			data->enemy.idling = 1;
		else
			data->enemy.idling = 0;
		frame_counter = 0;
		draw_all(data);
	}
	return (1);
}

int	create_window(char *path_map)
{
	t_data		data;

	data.path = ft_strdup(path_map);
	if (!load_data(&data))
		return (0);
	draw_all(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 0, close_all, &data);
	mlx_loop_hook(data.mlx, idling_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
