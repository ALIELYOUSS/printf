/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:55:00 by alel-you          #+#    #+#             */
/*   Updated: 2024/12/06 21:29:29 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

int	ft_putlow_hexa(unsigned long nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putlow_hexa(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putupp_hexa(unsigned long nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putupp_hexa(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putunbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
