/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:40:08 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/30 07:16:53 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	only_one_in_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			break ;
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	not_allowed_char(char c)
{
	const char	*charset = "01PCEZ";
	int			i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(char **strs, int y, int x)
{
	if (strs[y][x] == '1' || strs[y][x] == 'S')
		return ;
	if (strs[y][x] == '0' || strs[y][x] == 'P'
		|| strs[y][x] == 'C' || strs[y][x] == 'E')
	{
		strs[y][x] = 'S';
		flood_fill(strs, y, x + 1);
		flood_fill(strs, y, x - 1);
		flood_fill(strs, y + 1, x);
		flood_fill(strs, y - 1, x);
	}
	return ;
}

char	**dup_map(char **strs, int nb_lines)
{
	char	**strs_c;
	char	**strs_c_ptr;

	strs_c = (char **)malloc((nb_lines + 1) * sizeof(char *));
	if (!strs_c)
		return (NULL);
	strs_c_ptr = strs_c;
	while (*strs)
		*(strs_c++) = ft_strdup(*(strs++));
	*strs_c = NULL;
	return (strs_c_ptr);
}

int	*get_pos(char **strs, char to_find)
{
	int	*tab;
	int	x;
	int	y;

	tab = (int *)malloc(2 * sizeof(int));
	if (!tab)
		return (NULL);
	y = 0;
	while (strs[y])
	{
		x = 0;
		while (strs[y][x] != '\n' && strs[y][x])
		{
			if (strs[y][x] == to_find)
			{
				tab[0] = y;
				tab[1] = x;
				return (tab);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

/*
 *	not_allowed_char (check if the line have only allowed char)
 *	  get te char and the pos of the char if 
 *
 *	only_one (check if le line have only char '1')
 *
 *	dup_map
 *
 *	get_player_pos
 *
 */
