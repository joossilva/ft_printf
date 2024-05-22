/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:29:24 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/05/02 10:29:24 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Negatives: converts the number to a large positive number due to
	the two's complement wraparound. The function then formats this
	large positive number as a hexadecimal string.
*/

static int	ft_numsize_hexa(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_print_hexa(unsigned int n, char specifier)
{
	char	c;
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		ft_print_hexa(n / 16, specifier);
	c = base[n % 16];
	write(1, &c, 1);
	return (ft_numsize_hexa(n));
}

/*
int	main(void)
{
	int	count;

	count = ft_puthexa(-11, 'x');
	printf("\n"); fflush(stdout);
	printf("%i\n", count); fflush(stdout);
	count = printf("%x\n", -11);
	printf("%i\n", count);

	return(0);
}
*/
