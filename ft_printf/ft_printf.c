/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:28:12 by riccardobor       #+#    #+#             */
/*   Updated: 2023/02/17 12:41:22 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printunsignedint(unsigned int n)
{
	int					i;
	unsigned long int	nbr;

	nbr = n;
	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr < 0)
	{
		i += ft_putstr("(null)");
		return (6);
	}
	if (nbr > 9)
	{
		i += ft_printunsignedint(nbr / 10);
	}
	i += ft_putchar((nbr % 10) + 48);
	return (i);
}

int	ft_middle_step(va_list args, char indications)
{
	int	len;

	len = 0;
	if (indications == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (indications == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (indications == 'd' || indications == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (indications == 'p')
		len += ft_putpointer(va_arg(args, unsigned long long));
	else if (indications == 'u')
		len += ft_printunsignedint(va_arg(args, unsigned int));
	else if (indications == 'x')
		len += ft_printhexadecimallower(va_arg(args, unsigned int));
	else if (indications == 'X')
		len += ft_printhexadecimalupper(va_arg(args, int));
	else if (indications == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s1, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s1);
	while (s1[i])
	{
		if (s1[i] == '%')
		{
			len += ft_middle_step(args, s1[i + 1]);
			i++;
		}
		else
		len += ft_putchar(s1[i]);
	i++;
	}
	va_end(args);
	return (len);
}
