/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:21:56 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/24 18:03:54 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb >= 0 && nb <= 9)
		n += ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		n += ft_putnbr(nb / 10);
		n += ft_putchar(nb % 10 + '0');
	}
	else
	{
		n += ft_putchar('-');
		n += ft_putnbr(nb * -1);
	}
	return (n);
}
