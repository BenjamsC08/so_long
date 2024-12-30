/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:18:38 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 07:17:22 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_format(char **strs, int nb_lines, int base_len)
{
	int			y;
	int			x;

	y = -1;
	while (++y < nb_lines)
	{
		if (ft_nl_strlen(strs[y]) != base_len)
			return (-1);
		x = -1;
		while (++x < base_len)
		{
			if (y == 0 || y == (nb_lines - 1))
			{
				if (!only_one_in_line(strs[y]))
					return (-2);
				break ;
			}
			if ((x == 0 || x == (base_len - 1)) && strs[y][x] != '1')
				return (-3);
			else if (not_allowed_char(strs[y][x]))
				return (-4);
		}
	}
	return (1);
}

static int	check_nb_char(char **strs, int nb_lines, int line_len)
{
	int			x;
	int			y;
	static int	tab[3] = {0, 0, 0};

	y = -1;
	while (++y < nb_lines)
	{
		x = -1;
		while (++x < line_len)
		{
			if (strs[y][x] == 'C')
				tab[0]++;
			if (strs[y][x] == 'P')
				tab[1]++;
			if (strs[y][x] == 'E')
				tab[2]++;
		}
	}
	if (tab[0] < 1 || tab[1] != 1 || tab[2] != 1)
		return (-5);
	return (tab[0]);
}

static int	check_extension_path(char *path)
{
	int			last;
	int			i;
	const char	*r_ext = "reb.";

	last = ft_strlen(path) - 1;
	i = 0;
	while (i < 4)
	{
		if (path[last] != r_ext[i])
			return (-6);
		i++;
		last--;
	}
	return (1);
}

static int	check_map_doable(char **strs, int nb_lines, int len_line)
{
	int			x;
	int			y;
	int			*pos_p;

	pos_p = get_pos(strs, 'P');
	y = 0;
	flood_fill(strs, pos_p[0], pos_p[1]);
	free(pos_p);
	while (y < nb_lines)
	{
		x = 0;
		while (x < len_line)
		{
			if (strs[y][x] == 'C' || strs[y][x] == 'E' || strs[y][x] == 'P')
			{
				free_tabtab(strs);
				return (-7);
			}
			x++;
		}
		y++;
	}
	free_tabtab(strs);
	return (1);
}

int	check_map(char **strs, char *path_map, int nb_lines, int len_line)
{
	int		err_handler;
	char	**strs_copy;
	int		nb_collectible;

	nb_collectible = 0;
	err_handler = check_extension_path(path_map);
	if (err_handler < 0)
		return (err_management_map(err_handler, path_map), 0);
	err_handler = check_map_format(strs, nb_lines, len_line);
	if (err_handler < 0)
		return (err_management_map(err_handler, path_map), 0);
	err_handler = check_nb_char(strs, nb_lines, len_line);
	if (err_handler < 0)
		return (err_management_map(err_handler, path_map), 0);
	nb_collectible = err_handler;
	strs_copy = dup_map(strs, nb_lines);
	if (!strs_copy)
		return (err_management_map(-8, path_map), 0);
	err_handler = check_map_doable(strs_copy, nb_lines, len_line);
	if (err_handler < 0)
		return (err_management_map(err_handler, path_map), 0);
	return (nb_collectible);
}
/*
//check_map_format
////check '1' in border
////check if each line == strlen(line0)
//check_nb_char
////check if C>=1 if P == 1 if E == 1
////return nb_C
//check_extension_path
////check if the path finised by .ber
*/
