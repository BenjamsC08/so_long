/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:28:58 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 06:21:24 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**alloc_map(t_data *data)
{
	char		**map;
	int			i;
	const int	max_y = (data->height_win >> 5) - EXTRA_HEIGHT;
	const int	max_x = (data->width_win >> 5);

	map = (char **)ft_calloc(max_y + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < max_y)
	{
		map[i] = (char *)ft_calloc(max_x + 2, sizeof(char));
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
	int			*p_pos;
	int			*s_pos;
	const int	max_y = (data->height_win >> 5) - EXTRA_HEIGHT;
	const int	max_x = (data->width_win >> 5);

	s_pos = (int *)malloc(2 * sizeof(int));
	if (!s_pos)
		return (NULL);
	p_pos = get_player_pos(data->map.bp);
	if (p_pos[0] < 9)
		s_pos[0] = 0;
	else if ((data->map.y_max - p_pos[0]) < 9)
		s_pos[0] = p_pos[0] - (max_y - (data->map.y_max - p_pos[0]));
	else
		s_pos[0] = p_pos[0] - 8;
	if (p_pos[1] < 13)
		s_pos[1] = 0;
	else if ((data->map.x_max - p_pos[1]) < 13)
		s_pos[1] = p_pos[1] - (max_x - (data->map.x_max - p_pos[1]));
	else
		s_pos[1] = p_pos[1] - 12;
	free(p_pos);
	return (s_pos);
}

char	**extract_bp_to_win(t_data *data, int k)
{
	int		*start;
	char	**map;
	int		y;
	int		x;

	resize_map(data, k);
	map = alloc_map(data);
	if (!map)
		return (NULL);
	start = get_start_point(data);
	y = -1;
	while (++y < ((data->height_win >> 5) - EXTRA_HEIGHT))
	{
		x = -1;
		while (++x < (data->width_win >> 5))
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
