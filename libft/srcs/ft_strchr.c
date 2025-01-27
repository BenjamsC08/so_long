/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:41:36 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/11 21:41:39 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    const char * source = "The C Language";
    char * destination;
    char * pointer;
    int length = strlen( source );
    
    destination = (char *) malloc( sizeof( char) * (length+1) );
    strcpy( destination, source );

    while (pointer = strchr( destination, 'a' ) ) {
      *pointer = 'A';
    }
    printf( "Result : %s\n", destination );
    free( destination );
    
    return 0;
}*/
