/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:25:36 by benjamsc          #+#    #+#             */
/*   Updated: 2025/02/11 21:25:36 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_linedup(const char *s)
{
	int		l_src;
	char	*str;
	char	*src;

	l_src = ft_strlen(s);
	str = (char *)malloc((l_src + 1) * sizeof(char));
	if (!str)
		return (0);
	src = str;
	if (*s == '"')
		s++;
	while (*s && *s != '"')
		*(str++) = *(s++);
	*str = '\0';
	return (src);
}

static int	list_fill(char **list, int fd)
{
	char	**split;
	char	*line;

	split = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strncmp(line, "# define", 7) == 0)
		{
			split = ft_split(line, ' ');
			if (split && split[3])
			{
				*list = ft_linedup(split[3]);
				if (!(*list))
					return (0);
				list++;
			}
			free_tabtab(split);
		}
		free(line);
		line = get_next_line(fd);
	}
	*list = NULL;
	return (1);
}

static char	**list_img(void)
{
	char		**list;
	char		**save;
	const int	fd = open(PATH_TEXTURES, O_RDONLY);

	if (fd == -1)
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (NB_IMG + 2));
	if (!list)
		return (NULL);
	save = list;
	if (!list_fill(list, fd))
		return (close(fd), free_tabtab(list), NULL);
	close(fd);
	return (save);
}

static int	check_opened_map_img(void *mlx, int x, int y)
{
	void	*ptr;
	int		i;
	char	**list;

	i = 0;
	list = list_img();
	if (!list && !list[0])
		return (free_tabtab(list), 0);
	while (i < NB_IMG)
	{
		if (open(list[i], O_RDONLY) == -1)
			return (free_tabtab(list), 0);
		i++;
	}
	i = 0;
	while (i < NB_IMG)
	{
		ptr = mlx_xpm_file_to_image(mlx, list[i], &y, &x);
		if (!ptr)
			return (free_tabtab(list), 0);
		mlx_destroy_image(mlx, ptr);
		i++;
	}
	return (free_tabtab(list), 1);
}

int	checker(void)
{
	void	*m;
	int		r;
	int		x;
	int		y;

	x = TILE_SIZE;
	y = TILE_SIZE;
	r = 1;
	m = mlx_init();
	if (!m)
		return (0);
	if (!check_opened_map_img(m, x, y))
		r = 0;
	mlx_destroy_display(m);
	free(m);
	return (r);
}
