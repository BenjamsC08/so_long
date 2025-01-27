/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:57:27 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 20:57:34 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = 0;
	return ;
}
/*
void  ft_putstr(char *str, int max)
{
	int i = 0;
	if (max == -1)
		max = ft_strlen(str);
	while(i < max)
		write(1, &str[i++], 1);
}
int main()
{
	#include <stdio.h>
	#include <string.h>
	char str[50];
	memset(str, '8', 50);
	printf("before ft_bzero         : %s\n",str);
	ft_bzero(str,0);
	printf("after ft_bzero(str, 0)  : %s\n",str);
	ft_bzero(str,8);
	ft_putstr("after ft_bzero(str, 8)  : ", -1);
	ft_putstr(str, 50);
	write(1, "\n", 1);
	ft_bzero(str,25);
	ft_putstr("after ft_bzero(str, 25) : ", -1);
	ft_putstr(str, 50);
	write(1, "\n", 1);
	ft_bzero(str,50);
	ft_putstr("after ft_bzero(str, 50) : ", -1);
	ft_putstr(str, 50);

}*/
