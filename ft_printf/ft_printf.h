/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:37:49 by rbordin           #+#    #+#             */
/*   Updated: 2023/02/17 12:33:01 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s1, ...);
int	ft_check_args(const char *s1);
int	ft_middle_step(va_list args, char indication);
int	ft_putchar(int c);
int	ft_putstr(char *s1);
int	ft_count(long int n);
int	ft_putnbr(int n);
int	ft_unsigned_count(unsigned int n);
int	ft_putpointer(unsigned long long ptr);
int	ft_printhexadecimallower(unsigned int n);
int	ft_printhexadecimalupper(unsigned int n);
int	ft_count16(unsigned long long ptr);
int	ft_printunsignedint(unsigned int n);
int	ft_printpointer(unsigned long long n);

#endif
