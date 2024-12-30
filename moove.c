/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:55:38 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 03:46:24 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	swap_case(t_data *data, char axis, char to)
{
	const int	step = (const int)data->perso.step;
	int			*pos;

	pos = get_player_pos(data->map.bp);
	if (to == 'C')
	{
		to = '0';
		data->perso.nb_collectible++;
	}
	if (axis == 'X')
	{
		data->map.bp[pos[0]][pos[1]] = to;
		data->map.bp[pos[0]][pos[1] + step] = 'P';
	}
	if (axis == 'Y')
	{
		data->map.bp[pos[0]][pos[1]] = to;
		data->map.bp[pos[0] + step][pos[1]] = 'P';
	}
	if (data->map.win != data->map.bp)
	{
		free_tabtab(data->map.win);
		data->map.win = extract_bp_to_win(data);
	}
	free(pos);
}

static void	pre_swap(t_data *data)
{
	const char	**map = (const char**)data->map.bp;
	int			*pos;
	const int	step = (const int)data->perso.step;
	char		next_one;

	pos = get_player_pos(data->map.bp);
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
	/**/
	/*if (to == '1')*/
	/*	data->perso.moove_count--;*/
	/*if (to == 'Z')*/
	/*	good_ending(data);*/
	/*if (to == 'E')*/
	/*	ft_printf("la");*/
