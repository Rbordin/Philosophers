/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:52:48 by riccardobor       #+#    #+#             */
/*   Updated: 2023/02/17 12:44:56 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s1)
{
	int	i;

	i = 0;
	while (!s1)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s1)
	{
		i += ft_putchar(*s1);
		s1++;
	}
	return (i);
}

int	ft_count(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int			i;
	long int	nbr;

	nbr = n;
	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_putchar('-');
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
	}
	i += ft_putchar((nbr % 10) + 48);
	return (i);
}

int	ft_unsigned_count(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
