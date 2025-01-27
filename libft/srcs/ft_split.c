/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:39:17 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/13 18:41:23 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	char_is_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count_words(char *str, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (char_is_sep(*str, c))
		{
			if (in_word)
				words++;
			in_word = 0;
		}
		else
			in_word = 1;
		str++;
	}
	if (in_word)
		words++;
	return (words);
}

static char	*ft_dup_sep(char *src, char c)
{
	int		l_src;
	char	*str;
	int		i;

	l_src = 0;
	i = -1;
	while (src[l_src] && !char_is_sep(src[l_src], c))
		l_src++;
	str = (char *)malloc((l_src + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while ((++i) < l_src)
		str[i] = src[i];
	str[l_src] = '\0';
	return (str);
}

static void	free_all(char **strs)
{
	if (!strs)
		return ;
	while (*strs)
		free(*(strs++));
	free(strs);
}

char	**ft_split(const char *str, char c)
{
	char		**strs;
	const int	words = ft_count_words((char *)str, c);

	if (!str)
		return (NULL);
	strs = malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (*str)
	{
		if (!char_is_sep((char)*str, c))
		{
			*strs = ft_dup_sep((char *)str, c);
			if (! (*strs))
				return (free_all(strs), NULL);
			strs++;
			while (*str && !char_is_sep((char)*str, c))
				str++;
		}
		else
			str++;
	}
	*strs = NULL;
	return (strs - words);
}
/*
int main() 
{
    char *str = "^^^1^^2a,^^^^3^^^^--h^^^^";
    char sep = '^';
	//printf("%d",ft_count_words(str, sep));

    char **result = ft_split(str, sep);

	//printf("%s\n",result[0]);
    if (result != NULL)
	{
        for (int i = 0; result[i] != NULL; i++)
		{
			printf("Mot %d : %s : %p\n", i + 1, result[i], &result[i]);
        }

        for (int i = 0; result[i] != NULL; i++)
		{
            free(result[i]);
        }
        free(result);
    }
	else
	{
        printf("Erreur d'allocation mémoire pour la séparation.\n");
    }

    return (0);
}*/
