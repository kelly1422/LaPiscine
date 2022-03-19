/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:29:53 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/27 17:26:57 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <unistd.h>

void	rec(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	rec(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char		c;
	long long	n;

	n = nb;
	if (nb < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	rec(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = sign * -1;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	operate(int a, int b, char op)
{
	if (op == '+')
		ft_putnbr(sum(a, b));
	if (op == '-')
		ft_putnbr(sub(a, b));
	if (op == '*')
		ft_putnbr(mul(a, b));
	if (op == '/')
		ft_putnbr(div(a, b));
	if (op == '%')
		ft_putnbr(mod(a, b));
}

int	main(int argc, char *argv[])
{
	int		num1;
	int		num2;
	char	op;

	if (argc == 4)
	{
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		op = *argv[2];
		if (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%') \
				|| argv[2][1])
		{
			write(1, "0\n", 2);
			return (0);
		}
		if (num2 == 0 && op == '/')
			write(1, "Stop : division by zero", 23);
		else if (num2 == 0 && op == '%')
			write(1, "Stop : modulo by zero", 21);
		else
			operate(num1, num2, op);
		write(1, "\n", 1);
	}
	return (0);
}
