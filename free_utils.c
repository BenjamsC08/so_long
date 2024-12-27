/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:17:25 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/27 00:17:41 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_img1(t_data *data)
{
	if (data->tiles.door_c_ptr)
		mlx_destroy_image(data->mlx, data->tiles.door_c_ptr);
	if (data->tiles.door_o_ptr)
		mlx_destroy_image(data->mlx, data->tiles.door_o_ptr);
	if (data->tiles.ground_ptr)
		mlx_destroy_image(data->mlx, data->tiles.ground_ptr);
	if (data->tiles.wall_ptr)
		mlx_destroy_image(data->mlx, data->tiles.wall_ptr);
	if (data->map.img_ptr)
		mlx_destroy_image(data->mlx, data->map.img_ptr);
}

void	free_img(t_data *data)
{
	if (data->map.asset_ptr)
		mlx_destroy_image(data->mlx, data->map.asset_ptr);
	if (data->tiles.coll_ptr)
		mlx_destroy_image(data->mlx, data->tiles.coll_ptr);
	if (data->perso.left_ptr)
	{
		mlx_destroy_image(data->mlx, data->perso.left_ptr);
		mlx_destroy_image(data->mlx, data->perso.right_ptr);
		mlx_destroy_image(data->mlx, data->perso.up_ptr);
		mlx_destroy_image(data->mlx, data->perso.down_ptr);
	}
	if (data->enemy.left_ptr)
	{
		mlx_destroy_image(data->mlx, data->enemy.left_ptr);
		mlx_destroy_image(data->mlx, data->enemy.right_ptr);
		mlx_destroy_image(data->mlx, data->enemy.up_ptr);
		mlx_destroy_image(data->mlx, data->enemy.down_ptr);
	}
	free_img1(data);
}
