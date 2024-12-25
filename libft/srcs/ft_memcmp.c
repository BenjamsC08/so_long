/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:32:25 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:33:18 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	unsigned int		i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    char s[] = {-128, 0, 127, 0};
	  char sCpy[] = {-128, 0, 127, 0};
  	char s2[] = {0, 0, 127, 0};
	  char s3[] = {0, 0, 42, 0};
    size_t size = sizeof( int ) * 5;

    printf("%d =? %d\n",memcmp( s, sCpy, 4), ft_memcmp(s, sCpy, 4));
    printf("%d =? %d\n",memcmp(s, s2, 0), ft_memcmp(s, s2, 0));
    printf("%d =? %d\n",memcmp(s2, s, 1), ft_memcmp(s2, s, 1));
    printf("%d =? %d\n",memcmp(s2, s3, 4), ft_memcmp(s2, s3, 4));
    printf( "Test is ok\n" );
    
    return 0;
}*/
