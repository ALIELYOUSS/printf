/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:24:20 by alel-you          #+#    #+#             */
/*   Updated: 2024/12/07 16:22:18 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_format(char a, char b)
{
	if (a == '%' && b == 'c')
		return (1);
	if (a == '%' && b == 's')
		return (2);
	if (a == '%' && b == 'd')
		return (3);
	if (a == '%' && b == 'i')
		return (4);
	if (a == '%' && b == 'p')
		return (5);
	if (a == '%' && b == 'x')
		return (6);
	if (a == '%' && b == 'X')
		return (7);
	if (a == '%' && b == 'u')
		return (8);
	if (a == '%' && b == '%')
		return (9);
	return (0);
}

static int	impl_format(va_list args, int check)
{
	int	count;

	count = 0;
	if (check == 1)
		count += ft_putchar(va_arg(args, int));
	if (check == 2)
		count += ft_putstr(va_arg(args, char *));
	if (check == 3 || check == 4)
		count += ft_putnbr(va_arg(args, int));
	if (check == 5)
		count += ft_put_address(va_arg(args, void *));
	if (check == 6)
		count += ft_putlow_hexa(va_arg(args, unsigned int));
	if (check == 7)
		count += ft_putupp_hexa(va_arg(args, unsigned int));
	if (check == 8)
		count += ft_putunbr(va_arg(args, unsigned int));
	if (check == 9)
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		check;

	count = 0;
	i = 0;
	check = 0;
	if (!input)
		return (ft_putstr(NULL));
	va_start(args, input);
	while (input[i])
	{
		check = check_format(input[i], input[i + 1]);
		if (check > 0)
		{
			i += 2;
			count += impl_format(args, check);
			continue ;
		}
		count += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (count);
}
