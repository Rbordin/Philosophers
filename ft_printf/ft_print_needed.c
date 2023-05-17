/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_needed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:37:16 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/17 12:57:09 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr < 0)
	{
		len += ft_putstr("(null)");
		return (6);
	}
	if (ptr == 0)
	{
		len += ft_putstr("0x0");
		return (len);
	}
	else
	{
		len += ft_putstr("0x");
		len += ft_count16(ptr);
		ft_printpointer(ptr);
	}
	return (len);
}

int	ft_printpointer(unsigned long long n)
{
	int	count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n > 15)
	{
		ft_printpointer(n / 16);
		ft_printpointer(n % 16);
	}
	else if (n > 9)
	{
		ft_putchar(n - 10 + 'a');
	}
	if (n <= 9)
		ft_putchar(n + 48);
	count = ft_count16(n);
	return (count);
}

int	ft_printhexadecimallower(unsigned int n)
{
	int	count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n > 15)
	{
		ft_printhexadecimallower(n / 16);
		ft_printhexadecimallower(n % 16);
	}
	else if (n > 9)
	{
		ft_putchar(n - 10 + 'a');
	}
	if (n <= 9)
		ft_putchar(n + 48);
	count = ft_count16(n);
	return (count);
}

int	ft_printhexadecimalupper(unsigned int n)
{
	int	count;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n > 15)
	{
		ft_printhexadecimalupper(n / 16);
		ft_printhexadecimalupper(n % 16);
	}
	else if (n > 9)
		ft_putchar(n - 10 + 'A');
	if (n <= 9)
		ft_putchar(n + 48);
	count = ft_count16(n);
	return (count);
}

int	ft_count16(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}
