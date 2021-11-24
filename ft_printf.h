/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:57:56 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/24 18:28:54 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long nbr, char *base);

#endif
