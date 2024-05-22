/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:08:42 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/04/29 15:08:42 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char specifier, va_list arg)
{
	void	*ptr;

	if (specifier == 'c')
		return (ft_print_char(va_arg(arg, int)));
	if (specifier == '%')
		return (ft_print_char('%'));
	if (specifier == 's')
		return (ft_print_str(va_arg(arg, char *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(arg, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(arg, unsigned int)));
	if (specifier == 'p' )
	{
		ptr = (va_arg(arg, void *));
		if (ptr)
			return ((write (1, "0x", 2))
				+ (ft_print_address((long unsigned int)ptr)));
		else
			return (ft_print_str("(nil)"));
	}
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hexa(va_arg(arg, long int), specifier));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		result;

	count = 0;
	result = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
			result = ft_print_format(*++format, arg);
		else
			result = ft_print_char(*format);
		count += result;
		format++;
	}
	va_end(arg);
	return (count);
}
/*
int	main(void)
{
	int	count;
	int	*p;

	p = &count;
	printf("TESTS - f ft_printf | p printft \n\n"); fflush(stdout);
	printf("Test with Char: \n"); fflush(stdout);
	count = ft_printf("1) Test f %c\n", 'A');
	printf("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %c\n", 'A');
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test with String: \n"); fflush(stdout);
	count = ft_printf("1) Test f %s\n", "world!");
	printf("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %s\n", "world!");
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test with %%: \n"); fflush(stdout);
	count = ft_printf("1) Test f %%\n");
	printf("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %%\n");
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test with pointer: \n"); fflush(stdout);
	count = ft_printf("1) Test f %p\n", p);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %p\n", p); fflush(stdout);
	printf("Count: %i\n\n", count); fflush(stdout);
	printf("Test with pointer 0: \n"); fflush(stdout);
	count = ft_printf("2) Testf %p\n", (void *)0);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("2) Testp %p\n", (void *)0); fflush(stdout);
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test with decimal: \n"); fflush(stdout);
	count = ft_printf("1) Test f %d\n", -4294967);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %d\n", -4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("2) Test p %d\n", 4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("2) Test p %d\n", 4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("3) Test f %d\n", 0);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("3) Test p %d\n", 0); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("4) Test f %d\n", INT_MIN);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("4) Test p %d\n", INT_MIN); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("5) Test f %d\n", INT_MAX);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("5) Test p %d\n", INT_MAX); fflush(stdout);
	printf ("Count: %i\n\n", count); fflush(stdout);

	printf("Test with int: \n"); fflush(stdout);
	count = ft_printf("1) Test f %i\n", -4294967);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("1) Test p %i\n", -4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("2) Test p %i\n", 4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("2) Test p %i\n", 4294967); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("3) Test f %i\n", 0);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("3) Test p %i\n", 0); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("4) Test f %i\n", INT_MIN);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("4) Test p %i\n", INT_MIN); fflush(stdout);
	printf ("Count: %i\n", count); fflush(stdout);
	count = ft_printf("5) Test f %i\n", INT_MAX);
	printf ("Count: %i\n", count); fflush(stdout);
	count = printf("5) Test p %i\n", INT_MAX); fflush(stdout);
	printf ("Count: %i\n\n", count); fflush(stdout);

	printf("Test with unsigned int \n");  fflush(stdout);
	count = ft_printf("1) Test f %u\n", 4294967);
	printf("Count: %i\n", count);  fflush(stdout);
	count = printf("1) Test p %u\n", 4294967);  fflush(stdout);
	printf("Count: %i\n", count);  fflush(stdout);
	count = ft_printf("2) Test f %u\n", UINT_MAX);
	printf("Count: %i\n", count);  fflush(stdout);
	count = printf("2) Test p %u\n", UINT_MAX);  fflush(stdout);
	printf("Count: %i\n", count);  fflush(stdout);
	count = ft_printf("3) Test f %u\n", 0);
	printf("Count: %i\n", count);  fflush(stdout);
	count = printf("3) Test p %u\n", 0);  fflush(stdout);
	printf("Count: %i\n\n", count);  fflush(stdout);

	printf("Test with hexadecimal(x): \n");
	count = ft_printf("1) Test f %x\n", 20);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("1) Test p %x\n", 20);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);
	count = ft_printf("2) Test f %x\n", 0xa);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("2) Test p %x\n", 0xa);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);
	count = ft_printf("3) Test f %x\n", -10);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("3) Test p %x\n", -10);  fflush(stdout);
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test with hexadecimal (X):\n"); fflush(stdout);
	count = ft_printf("1) Test f %X\n", 20);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("1) Test p %X\n", 20);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);
	count = ft_printf("2) Test f %X\n", 0xa);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("2) Test p %X\n", 0xa);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);
	count = ft_printf("3) Test f %X\n", -10);
	printf("Count: %i\n", count); fflush(stdout);
	count =printf("3) Test p %X\n", -10);  fflush(stdout);
	printf("Count: %i\n\n", count); fflush(stdout);

	printf("Test mix:\n"); fflush(stdout);
	count = ft_printf("1) Test f %c %s %p %d %i %u %x %X \n", 'a', "Hello",
		p, 123, 123, 123, -2, -2);
	printf("Count: %i\n", count); fflush(stdout);
		count =printf("1) Test p %c %s %p %d %i %u %x %X \n", 'a', "Hello", p,
	123, 123, 123, -2, -2);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);

	printf("Test NULO"); fflush(stdout);
	//count = ft_printf(NULL);
	//printf("Count: %i\n", count); fflush(stdout);
	count = printf(NULL);  fflush(stdout);
	printf("Count: %i\n", count); fflush(stdout);

	return(0);
}
*/