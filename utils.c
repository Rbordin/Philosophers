/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:32:02 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/11 15:45:49 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sign(char c)
{
	int	sign;

	sign = 1;
	if (c == '-')
		sign *= -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] != '\0' && (str[i] >= 9 && str[i] <= 13))
		|| str[i] == 32 || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign *= ft_sign(str[i]);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		j = (j * 10) + (str[i] - 48);
		i++;
	}	
	return ((int)(sign * j));
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