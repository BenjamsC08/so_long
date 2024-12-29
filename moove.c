/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 01:55:38 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/23 02:29:13 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	swap_case(t_data *data, char axis, char to)
{
	const int	step = (const int)data->perso.step;
	int			*pos;

	pos = get_player_pos(data->map.bp);
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
}

static void	parse_swap(t_data *data, char axis, char to)
{
	int			*pos;

	pos = get_player_pos(data->map.bp);
	if (to == 'Z')
		good_ending(data);
	if (to == 'E')
		ft_printf("la");
	if (to == 'C')
	{
		to = '0';
		data->perso.nb_collectible++;
	}
	if (axis == 'X')
		swap_case(data, axis, to);
	if (axis == 'Y')
		swap_case(data, axis, to);
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

	pos = get_player_pos(data->map.bp);
	if (data->perso.dir == 'R' || data->perso.dir == 'L')
	{
		if (map[pos[0]][(pos[1] + step)] != '1'
			&& map[pos[0]][(pos[1] + step)] != 'E')
			parse_swap(data, 'X', map[pos[0]][(pos[1] + step)]);
	}
	if (data->perso.dir == 'U' || data->perso.dir == 'D')
	{
		if (map[(pos[0] + step)][pos[1]] != '1'
			&& map[(pos[0] + step)][pos[1]] != 'E')
			parse_swap(data, 'Y', map[pos[0] + step][pos[1]]);
	}
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
