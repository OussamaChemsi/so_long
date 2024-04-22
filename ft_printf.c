/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochemsi <ochemsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:35:15 by ochemsi           #+#    #+#             */
/*   Updated: 2024/04/22 06:02:31 by ochemsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

static void	print_format(char specifier, va_list ap)
{
	if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(ap, int));
	else
		ft_putchar(specifier);
}

void	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			print_format(format[++i], ap);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
}
