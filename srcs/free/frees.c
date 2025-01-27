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
}

int	close_all(t_data *data)
{
	classic_close(data);
	if (data->map.win != data->map.bp)
		free_tabtab(data->map.win);
	if (data->map.bp != NULL)
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
	if (!strs)
		return ;
	if (!strs[i])
		return (free(strs));
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
