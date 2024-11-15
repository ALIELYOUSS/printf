/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:29:26 by alel-you          #+#    #+#             */
/*   Updated: 2024/11/14 21:09:54 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <string.h>
void	ft_check_format(char *buff, ...)
{
	va_list	args;
	va_start(args, buff);
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '%' && buff[i + 1] == 'd')
		{
			i += 2;
			void * x = va_arg(args, void *);
			ft_putnbr_fd((int)x, 1);
			continue ;
		}
		if (buff[i] == '%' && buff[i + 1] == 's')
		{
			i += 2;
			void * x = va_arg(args, void *);
			write(1, (char *)x, strlen((char *)x));
			continue ;
		}
		if (buff[i] == '%' && buff[i + 1] == 'c')
		{
			i += 2;
			void * x = va_arg(args, void *);
			ft_putchar_fd((char)x, 1);
			continue ;
		}
		write(1, &buff[i], 1);
		i++;
	}
}

int main()
{
	int i = 5;
	ft_check_format("tset1 == %d || %s || %c\n", i, "gggg", 'c');
	printf("tset1 == %d || %s || %c\n", i, "gggg", 'c');
}