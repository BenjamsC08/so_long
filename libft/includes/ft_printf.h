/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:05:44 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 23:29:57 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"

int		ft_intlen(unsigned int nb, char type);
int		ft_xlen(unsigned long nbr);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_xtoa(unsigned long nbr, char type);

int		ft_put_char_int(char c);
int		ft_put_str_int(char *str);

int		ft_put_nbr_int(int nbr);
int		ft_put_uint_int(unsigned int nb);
int		ft_put_hex_int(unsigned int nbr, char type);
int		ft_put_ptr_int(unsigned long nbr);

int		ft_printf(const char *str, ...);

#endif
