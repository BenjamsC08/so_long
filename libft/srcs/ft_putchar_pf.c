/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:35:29 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:36:31 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_char_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_str_int(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (ft_put_str_int("(null)"));
	while (*str)
		len += ft_put_char_int(*(str++));
	return (len);
}
