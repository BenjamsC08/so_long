/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:15:56 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/08 18:19:04 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_img(t_data *data)
{
	if (data->tiles.door_data[1])
		mlx_destroy_image(data->mlx, data->tiles.door_ptr[1]);
	if (data->tiles.door_data[0])
		mlx_destroy_image(data->mlx, data->tiles.door_ptr[0]);
	if (data->tiles.ground_data[3])
		mlx_destroy_image(data->mlx, data->tiles.ground_ptr[3]);
	if (data->tiles.ground_data[2])
		mlx_destroy_image(data->mlx, data->tiles.ground_ptr[2]);
	if (data->tiles.ground_data[1])
		mlx_destroy_image(data->mlx, data->tiles.ground_ptr[1]);
	if (data->tiles.ground_data[0])
		mlx_destroy_image(data->mlx, data->tiles.ground_ptr[0]);
	if (data->tiles.ground_ptr)
		free(data->tiles.ground_ptr);
	if (data->tiles.ground_data)
		free(data->tiles.ground_data);
	if (data->tiles.wall_ptr)
		mlx_destroy_image(data->mlx, data->tiles.wall_ptr);
	if (data->map.img_ptr)
		mlx_destroy_image(data->mlx, data->map.img_ptr);
}

static void	free_img_perso(t_data *data)
{
	if (data->perso.left_ptr[1])
		mlx_destroy_image(data->mlx, data->perso.left_ptr[1]);
	if (data->perso.left_ptr[0])
		mlx_destroy_image(data->mlx, data->perso.left_ptr[0]);
	if (data->perso.right_ptr[1])
		mlx_destroy_image(data->mlx, data->perso.right_ptr[1]);
	if (data->perso.right_ptr[0])
		mlx_destroy_image(data->mlx, data->perso.right_ptr[0]);
	if (data->perso.up_data[1])
		mlx_destroy_image(data->mlx, data->perso.up_ptr[1]);
	if (data->perso.up_data[0])
		mlx_destroy_image(data->mlx, data->perso.up_ptr[0]);
	if (data->perso.down_data[1])
		mlx_destroy_image(data->mlx, data->perso.down_ptr[1]);
	if (data->perso.down_data[0])
		mlx_destroy_image(data->mlx, data->perso.down_ptr[0]);
	try_to_free_player(data);
}

static void	free_img_enemy(t_data *data)
{
	if (data->enemy.left_ptr[1])
		mlx_destroy_image(data->mlx, data->enemy.left_ptr[1]);
	if (data->enemy.left_ptr[0])
		mlx_destroy_image(data->mlx, data->enemy.left_ptr[0]);
	if (data->enemy.right_ptr[1])
		mlx_destroy_image(data->mlx, data->enemy.right_ptr[1]);
	if (data->enemy.right_ptr[0])
		mlx_destroy_image(data->mlx, data->enemy.right_ptr[0]);
	if (data->enemy.up_data[1])
		mlx_destroy_image(data->mlx, data->enemy.up_ptr[1]);
	if (data->enemy.up_data[0])
		mlx_destroy_image(data->mlx, data->enemy.up_ptr[0]);
	if (data->enemy.down_data[1])
		mlx_destroy_image(data->mlx, data->enemy.down_ptr[1]);
	if (data->enemy.down_data[0])
		mlx_destroy_image(data->mlx, data->enemy.down_ptr[0]);
	try_to_free_enemy(data);
}

void  free_img(t_data *data)
{
	if (data->map.asset_data)
		mlx_destroy_image(data->mlx, data->map.asset_ptr);
	if (data->tiles.coll_ptr)
		mlx_destroy_image(data->mlx, data->tiles.coll_ptr);
	free_map_img(data);
	free_img_perso(data);
	if (data->enemy.is_on == 1 && data->enemy.left_ptr)
		free_img_enemy(data);
}
