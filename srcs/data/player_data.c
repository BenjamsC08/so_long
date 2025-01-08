/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:14:00 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 11:15:14 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_img(t_data *data)
{
	data->perso.down_ptr = mlx_xpm_file_to_image(data->mlx,
			PLAYER_DOWN_1, &data->tiles.size, &data->tiles.size);
	data->perso.down_data = (int *)mlx_get_data_addr(data->perso.down_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.up_ptr = mlx_xpm_file_to_image(data->mlx,
			PLAYER_UP_1, &data->tiles.size, &data->tiles.size);
	data->perso.up_data = (int *)mlx_get_data_addr(data->perso.up_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.right_ptr = mlx_xpm_file_to_image(data->mlx,
			PLAYER_RIGHT_1, &data->tiles.size, &data->tiles.size);
	data->perso.right_data = (int *)mlx_get_data_addr(data->perso.right_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
	data->perso.left_ptr = mlx_xpm_file_to_image(data->mlx,
			PLAYER_LEFT_1, &data->tiles.size, &data->tiles.size);
	data->perso.left_data = (int *)mlx_get_data_addr(data->perso.left_ptr,
			&data->map.bpp, &data->map.line_len, &data->map.endian);
}

void	player_data(t_data *data)
{
	player_img(data);
	data->perso.dir = 'D';
	data->perso.step = 0;
	data->perso.nb_collectible = 0;
}
