/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@email.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:43:07 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:44:28 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_nbr_int(int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_put_char_int('0'));
	s1 = ft_itoa(nb);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_uint_int(unsigned int nb)
{
	char	*s;
	char	*s1;
	int		len;

	if (nb == 0)
		return (ft_put_char_int('0'));
	s1 = ft_utoa(nb);
	if (!s1)
		return (0);
	s = s1;
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_hex_int(unsigned int nbr, char type)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_put_char_int('0'));
	s1 = ft_xtoa(nbr, type);
	s = s1;
	if (nbr == 0)
		return (ft_put_char_int('0'));
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int	ft_put_ptr_int(unsigned long nbr)
{
	char	*s;
	char	*s1;
	int		len;

	if (nbr == 0)
		return (ft_put_str_int("(nil)"));
	s1 = ft_xtoa(nbr, 'x');
	s = s1;
	write(1, "0x", 2);
	while (*s1)
		write(1, (s1++), 1);
	len = ft_strlen(s);
	free(s);
	return (len + 2);
}
