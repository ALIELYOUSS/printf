/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:56:14 by alel-you          #+#    #+#             */
/*   Updated: 2024/12/07 16:30:23 by alel-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putlow_hexa(unsigned long nb);
int	ft_putupp_hexa(unsigned long nb);
int	ft_putunbr(unsigned int nb);
int	ft_putstr(char *str);
int	ft_put_address(void *loc);
int	ft_printf(const char *input, ...);

#endif