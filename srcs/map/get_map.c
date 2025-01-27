/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:23:19 by benjamsc          #+#    #+#             */
/*   Updated: 2025/01/17 03:34:49 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *path_map)
{
	int		fd;
	int		nb_lines;
	char	*str;

	nb_lines = 0;
	fd = open((char *)path_map, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str != NULL)
	{
		nb_lines++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (nb_lines);
}

char	**get_map(t_data *data, int *len_line)
{
	char		*str;
	char		**strs;
	const int	fd = open((char *)data->path, O_RDONLY);
	static int	i = 0;

	strs = malloc(sizeof(char *) * (data->map.y_max + 1));
	if (!strs)
		return (NULL);
	str = get_next_line(fd);
	while (i < data->map.y_max && str != NULL)
	{
		if (i == 0)
			*len_line = ft_nl_strlen(str);
		strs[i++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	strs[i] = NULL;
	close(fd);
	data->collectibles = check_map(strs, data, *len_line);
	if (data->collectibles == 0)
		return (free_tabtab(strs), NULL);
	strs = map_diversity(data, strs);
	return (strs);
}
