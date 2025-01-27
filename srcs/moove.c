/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:55:38 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/17 03:58:43 by benjamsc         ###   ########.fr       */
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
	const int	step = (const int)data->perso.step;
	int			*pos;

	pos = get_pos(data->map.bp, 'P');
	if (to == 'C')
	{
		to = '0';
		data->perso.nb_collectible++;
	}
	if (axis == 'X')
	{
		data->map.bp[pos[0]][pos[1]] = swap_ground(to);
		data->map.bp[pos[0]][pos[1] + step] = 'P';
	}
	if (axis == 'Y')
	{
		data->map.bp[pos[0]][pos[1]] = swap_ground(to);
		data->map.bp[pos[0] + step][pos[1]] = 'P';
	}
	if (data->map.win != data->map.bp)
	{
		free_tabtab(data->map.win);
		data->map.win = extract_bp_to_win(data, data->type_resize);
	}
	free(pos);
}

static void	pre_swap(t_data *data)
{
	const char	**map = (const char **)data->map.bp;
	int			*pos;
	const int	step = (const int)data->perso.step;
	char		next_one;

	pos = get_pos(data->map.bp, 'P');
	next_one = map[pos[0]][(pos[1] + step)];
	if (data->perso.dir == 'R' || data->perso.dir == 'L')
	{
		if (next_one != '1' && next_one != 'E' && next_one != 'Z')
			swap_case(data, 'X', next_one);
	}
	else if (data->perso.dir == 'U' || data->perso.dir == 'D')
	{
		next_one = map[(pos[0] + step)][pos[1]];
		if (next_one != '1' && next_one != 'E' && next_one != 'Z')
			swap_case(data, 'Y', next_one);
	}
	if ((next_one == 'E' && is_ok(data)) || next_one == 'Z')
		ending(data, next_one, pos);
	if (next_one == '1' || (next_one == 'E' && !is_ok(data)))
		data->perso.moove_count--;
	free(pos);
}

void	moove(t_data *data, int keycode)
{
	data->perso.moove_count++;
	if (keycode == U_ARROW || keycode == W_KEY)
	{
		data->perso.dir = 'U';
		data->perso.step = -1;
	}
	if (keycode == D_ARROW || keycode == S_KEY)
	{
		data->perso.dir = 'D';
		data->perso.step = 1;
	}
	if (keycode == R_ARROW || keycode == D_KEY)
	{
		data->perso.dir = 'R';
		data->perso.step = 1;
	}
	if (keycode == L_ARROW || keycode == A_KEY)
	{
		data->perso.dir = 'L';
		data->perso.step = -1;
	}
	pre_swap(data);
}
