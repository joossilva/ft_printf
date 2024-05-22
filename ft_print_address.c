/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:15:30 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/05/02 18:15:30 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numsize_adress(long unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count ++;
	}
	return (count);
}

int	ft_print_address(long unsigned int n)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_print_address(n / 16);
	c = base[n % 16];
	write(1, &c, 1);
	return (ft_numsize_adress(n));
}
