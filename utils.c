/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:32:02 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/19 12:21:22 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
			print_error();
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		print_error();
	return (result * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	int		i;

	i = 0;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	a = (void *)malloc(count * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (count * size));
	return (a);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s && !n)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}