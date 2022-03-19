/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:52:16 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/19 17:18:07 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_c_16(unsigned char c, int i)
{
	char	num1;
	char	num2;

	num1 = ((int)c / 16) + '0';
	num2 = ((int)c % 16) + '0';
	if (num1 > '9')
		num1 = num1 + 39;
	if (num2 > '9')
		num2 = num2 + 39;
	write(1, &num1, 1);
	write(1, &num2, 1);
	if (i % 2 == 1)
		write(1, " ", 1);
}

void	rec(unsigned long long	num, char *s, int idx)
{
	char	c;

	if (num == 0)
		return ;
	rec(num / 16, s, idx + 1);
	c = num % 16 + '0';
	if (c > '9')
		c += 39;
	s[idx] = c;
}

unsigned long long	*print_addr_16(unsigned long long	addr, int idx)
{
	int		i;	
	char	s[16];

	i = 0;
	while (i < 16)
		s[i++] = '0';
	i = 15;
	rec(addr, s, 0);
	if (idx != 0)
		write(1, "\n", 1);
	while (i >= 0)
		write(1, &s[i--], 1);
	write(1, ": ", 2);
	addr = addr + 16;
	return ((unsigned long long *)addr);
}

char	*print_sentence(char *str, int n)
{
	int	i;

	i = 0;
	str = str - n;
	while (i < n)
	{
		if ((*str >= 0 && *str <= 31) || *str == 127)
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
		i++;
	}
	return (str);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	char				*str;
	unsigned long long	*str3;

	str = addr;
	str3 = addr;
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
			str3 = print_addr_16((unsigned long long)str3, i);
		print_c_16(*str++, i);
		if (i++ % 16 == 15)
			str = print_sentence(str, 16);
	}
	i = size % 16;
	while (i < 16)
	{
		if (i++ % 2 == 1)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
	print_sentence(str, size % 16);
	return (addr);
}
