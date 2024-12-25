/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:17:39 by benjamsc          #+#    #+#             */
/*   Updated: 2024/12/23 00:58:16 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (2 == argc && open(argv[1], O_RDONLY) > 0)
	{
		create_window(argv[1]);
	}
	else
	{
		ft_printf("%s", "Nb args, Path or Access is not correct");
		ft_printf("%s\n", " ex: ./so_long mapX.ber");
	}
}
