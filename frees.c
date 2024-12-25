/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:58:04 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/23 01:27:01 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void free_img(t_data *data);

int	close_all(t_data *data)
{
	free(data->path);
	if (data->map.win != data->map.bp)
		free_tabtab(data->map.win);
	free_tabtab(data->map.bp);
	data->map.bp = NULL;
  free_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	free_tabtab(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_aprox_map(char **map, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
}

static void free_img(t_data *data)
{
  mlx_destroy_image(data->mlx, data->map.asset_ptr);
	mlx_destroy_image(data->mlx, data->tiles.coll_ptr);
	mlx_destroy_image(data->mlx, data->perso.left_ptr);
	mlx_destroy_image(data->mlx, data->perso.right_ptr);
	mlx_destroy_image(data->mlx, data->perso.up_ptr);
	mlx_destroy_image(data->mlx, data->perso.down_ptr);
  mlx_destroy_image(data->mlx, data->enemy.left_ptr);
	mlx_destroy_image(data->mlx, data->enemy.right_ptr);
	mlx_destroy_image(data->mlx, data->enemy.up_ptr);
	mlx_destroy_image(data->mlx, data->enemy.down_ptr);
	mlx_destroy_image(data->mlx, data->tiles.door_c_ptr);
	mlx_destroy_image(data->mlx, data->tiles.door_o_ptr);
	mlx_destroy_image(data->mlx, data->tiles.ground_ptr);
	mlx_destroy_image(data->mlx, data->tiles.wall_ptr);
	mlx_destroy_image(data->mlx, data->map.img_ptr);
}
