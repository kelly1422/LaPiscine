/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:17:28 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:03:46 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min_calc(int row, int col, int diag)
{
	if (row <= col && row <= diag)
		return (row);
	else if (col <= row && col <= diag)
		return (col);
	else
		return (diag);
}

int	check_pos(int x, int y)
{
	if (x - 1 < 0 || y - 1 < 0)
		return (0);
	return (1);
}

int	ft_atoin(char *str, int size)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && i < size)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	is_wrong(unsigned char a, unsigned char b, \
	unsigned char c, t_map_info *info)
{
	if (a < 32 || a > 126)
		return (1);
	if (b < 32 || b > 126)
		return (1);
	if (c < 32 || c > 126)
		return (1);
	if (a != b && b != c)
	{
		info->full = a;
		info->obs = b;
		info->empty = c;
		return (0);
	}
	return (1);
}
