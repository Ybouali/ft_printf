/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:25:09 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/24 18:30:01 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_check(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

static unsigned int	ft_len_of_base_and_check(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_check(base);
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_putnbr_new(unsigned int l, char *b_n, unsigned long nbr, int *n)
{
	unsigned long	nbr01;
	static int		n2;

	n2 = *n;
	nbr01 = nbr;
	if (nbr01 >= l)
	{
		ft_putnbr_new(l, b_n, nbr01 / l, &n2);
		ft_putnbr_new(l, b_n, nbr01 % l, &n2);
	}
	else
	{
		n2++;
		write (1, &b_n[nbr01], 1);
	}
	return (n2);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int	lenofbase;
	int				n;

	n = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	lenofbase = ft_len_of_base_and_check(base);
	if (lenofbase == 0)
		return (0);
	n = ft_putnbr_new(lenofbase, base, nbr, &n);
	return (n);
}
