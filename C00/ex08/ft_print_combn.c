/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:57:53 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/09 14:00:46 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_arr[10];

void	rec(int front, int n, int num)
{
	int	i;

	if (num == n)
	{
		write(1, g_arr, n);
		write(1, ", ", 2);
		return ;
	}
	if (front == 9)
		return ;
	i = front + 1;
	while (i <= 10 - n + num)
	{
		g_arr[num] = '0' + i;
		rec(i, n, num + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	last;

	i = 0;
	while (i < 10 - n)
	{
		g_arr[0] = '0' + i;
		rec(i, n, 1);
		i++;
	}
	if (i == 10 - n)
	{
		while (i < 10)
		{
			last = '0' + i++;
			write(1, &last, 1);
		}
	}
}
