/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:58:04 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/27 00:58:54 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	classic_close(t_data *data)
{
	free(data->path);
	if (data->map.win && data->map.win != data->map.bp)
		free_tabtab(data->map.win);
	if (data->map.bp != NULL)
		free_tabtab(data->map.bp);
}

int	close_all(t_data *data)
{
	classic_close(data);
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

void    in_run_free(t_data *data)
{
  try_to_free_overlay(data);
  try_to_free_player(data);
  try_to_free_enemy(data);
  classic_close(data);
  mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}
