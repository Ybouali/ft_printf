/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:57:05 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/24 18:01:25 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	index;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	index = 0;
	while (str[index])
	{
		write (1, &str[index], 1);
		index++;
	}
	return (index);
}
