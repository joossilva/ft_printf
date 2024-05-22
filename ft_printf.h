/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:20:26 by jrocha-f          #+#    #+#             */
/*   Updated: 2024/05/02 15:20:26 by jrocha-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

int	ft_print_nbr(int n);
int	ft_print_hexa(unsigned int n, char specifier);
int	ft_printf(const char *format, ...);
int	ft_print_address(long unsigned int n);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_unsigned(unsigned int n);

#endif