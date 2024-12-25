/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:28:58 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/22 23:08:52 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**alloc_map(void)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(MAX_Y_WIN + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < MAX_Y_WIN)
	{
		map[i] = (char *)ft_calloc(MAX_X_WIN + 2, sizeof(char));
		if (!map[i])
		{
			free_aprox_map(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static int	*get_start_point(t_data *data)
{
	int	*p_pos;
	int	*s_pos;

	s_pos = (int *)malloc(2 * sizeof(int));
	if (!s_pos)
		return (NULL);
	p_pos = get_player_pos(data->map.bp);
	if (p_pos[0] < 9)
		s_pos[0] = 0;
	else if ((data->map.y_max - p_pos[0]) < 9)
		s_pos[0] = p_pos[0] - (MAX_Y_WIN - (data->map.y_max - p_pos[0]));
	else
		s_pos[0] = p_pos[0] - 8;
	if (p_pos[1] < 13)
		s_pos[1] = 0;
	else if ((data->map.x_max - p_pos[1]) < 13)
		s_pos[1] = p_pos[1] - (MAX_X_WIN - (data->map.x_max - p_pos[1]));
	else
		s_pos[1] = p_pos[1] - 12;
	free(p_pos);
	return (s_pos);
}

char	**extract_bp_to_win(t_data *data)
{
	int		*start;
	char	**map;
	int		y;
	int		x;

	map = alloc_map();
	if (!map)
		return (NULL);
	start = get_start_point(data);
	y = -1;
	while (++y < MAX_Y_WIN)
	{
		x = -1;
		while (++x < MAX_X_WIN)
		{
			map[y][x] = data->map.bp[start[0] + y][start[1] + x];
		}
		map[y][x] = '\n';
	}
	free(start);
	return (map);
}

// le but est de recuperer Y et X du player et regarder la distance 
// qu'il est du top/down et de left/right avec map x_max et map.y_max
// un fois que l'on a ont essaye de mettre le player le plus au centre possible
//
// sachant que win fait 17 x 25
//
