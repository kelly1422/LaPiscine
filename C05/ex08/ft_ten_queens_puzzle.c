/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:08:50 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/19 21:00:50 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count = 0;
int	g_board[10];

int	promising(int cdx)
{
	int	i;
	int	n;

	i = 0;
	while (i < cdx)
	{
		if (g_board[cdx] == g_board[i])
			return (0);
		n = g_board[cdx] - g_board[i];
		if (n < 0)
			n = n * -1;
		if (cdx - i == n)
			return (0);
		i++;
	}
	return (1);
}

void	print(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = g_board[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	nqueen(int cdx)
{
	int	i;

	i = 0;
	if (cdx == 10)
	{
		print();
		g_count++;
		return ;
	}
	while (i < 10)
	{
		g_board[cdx] = i;
		if (promising(cdx))
			nqueen(cdx + 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	nqueen(0);
	return (g_count);
}
