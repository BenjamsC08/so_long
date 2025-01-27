/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:38:40 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:39:12 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*s1;

	s1 = s - 1;
	while (*(++s1))
		write(fd, s1, 1);
}
/*
int main()
{
  #include <fcntl.h>
  int fd = open("text.txt",O_WRONLY);
  ft_putstr_fd("trou",fd);
  close(fd);
}*/
