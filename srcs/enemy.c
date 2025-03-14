/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:15:59 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 12:05:20 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	swap_ground(char to)
{
	char		other;
	static char	temp = '0';

	other = temp;
	temp = to;
	to = other;
	return (to);
}

static void	swap_case(t_data *data, char axis, char to)
{
	const int	step = (const int)data->enemy.step;
	int			*pos;
	static int	n = 0;

	if (n != 2)
	{
		pos = get_pos(data->map.bp, 'Z');
		if (axis == 'X')
		{
			data->map.bp[pos[0]][pos[1]] = swap_ground(to);
			data->map.bp[pos[0]][pos[1] + step] = 'Z';
		}
		if (axis == 'Y')
		{
			data->map.bp[pos[0]][pos[1]] = swap_ground(to);
			data->map.bp[pos[0] + step][pos[1]] = 'Z';
		}
		free(pos);
	}
	else
		n = -1;
	n++;
}

static void	pre_swap(t_data *data, int *p_pos, int *z_pos)
{
	const char	**map = (const char**)data->map.bp;
	const int	step = (const int)data->enemy.step;
	char		next_one;

	free(p_pos);
	next_one = map[z_pos[0]][(z_pos[1] + step)];
	if (data->enemy.dir == 'R' || data->enemy.dir == 'L')
	{
		if (next_one != '1' && next_one != 'E' && next_one != 'P'
			&& next_one != 'C')
			swap_case(data, 'X', next_one);
		else if (next_one == '1')
			data->enemy.dir = 'U';
	}
	if (data->enemy.dir == 'U' || data->enemy.dir == 'D')
	{
		next_one = map[(z_pos[0] + step)][z_pos[1]];
		if (next_one != '1' && next_one != 'E' && next_one != 'P'
			&& next_one != 'C')
			swap_case(data, 'Y', next_one);
	}
	free(z_pos);
}

void	enemy_moove(t_data *data)
{
	const int	*p_pos = get_pos(data->map.bp, 'P');
	int			*z_pos;

	z_pos = get_pos(data->map.bp, 'Z');
	if (p_pos[0] < z_pos[0])
	{
		data->enemy.dir = 'U';
		data->enemy.step = -1;
	}
	else if (p_pos[0] > z_pos[0])
	{
		data->enemy.dir = 'D';
		data->enemy.step = 1;
	}
	else if (p_pos[1] < z_pos[1])
	{
		data->enemy.dir = 'L';
		data->enemy.step = -1;
	}
	else if (p_pos[1] > z_pos[1])
	{
		data->enemy.dir = 'R';
		data->enemy.step = 1;
	}
	pre_swap(data, (int *)p_pos, z_pos);
}
