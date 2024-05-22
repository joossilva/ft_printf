/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:04:36 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/04/30 14:04:36 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numsize(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count ++;
		while (n <= (-10))
		{
			n /= 10;
			count ++;
		}
	}
	if (n >= 0)
	{
		while (n >= 10)
		{
			n /= 10;
			count ++;
		}
	}
	return (count);
}

int	ft_print_nbr(int n)
{
	long int		nb;
	unsigned char	c;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_print_nbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (ft_numsize(n));
}
/*
int	main(void)
{
	int	count;

	count = ft_print_nbr(INT_MIN);
	printf("\n"); fflush(stdout);
	printf("%i\n", count); fflush(stdout);
	return(0);
}
*/