/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:13:23 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/09 14:14:10 by rbordin          ###   ########.fr       */
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