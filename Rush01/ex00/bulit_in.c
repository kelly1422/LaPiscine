/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulit_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:21:29 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 15:36:28 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_first_process(int	*input, int	**map)
{
	int	idx;

	idx = -1;
	while (++idx < g_size * 4)
	{
		if (input[idx] == g_size)
		{
			if (idx < g_size * 2)
				ft_col_max(idx, map);
			else
				ft_row_max(idx - (g_size * 2), map);
		}
		else if (input[idx] == 1)
			ft_col_row_1(idx, map);
		else
			continue ;
	}
}

void	ft_row_max(int	idx, int	**map)
{
	int	value;
	int	row;
	int	i;

	row = idx % g_size;
	if (idx < g_size)
	{
		value = 0;
		i = row * g_size;
		while (++value <= g_size)
		{
			ft_put_map(i++, map, value);
		}
	}
	else
	{
		value = 0;
		i = (row + 1) * g_size - 1;
		while (++value <= g_size)
		{
			ft_put_map(i--, map, value);
		}
	}
}

void	ft_col_max(int	idx, int	**map)
{
	int	col;
	int	value;
	int	i;

	col = idx % g_size;
	if (idx < g_size)
	{
		value = 0;
		i = col;
		while (++value <= g_size)
		{
			ft_put_map(i, map, value);
			i += g_size;
		}
	}
	else
	{
		value = 0;
		i = g_size * (g_size - 1) + col;
		while (++value <= g_size)
		{
			ft_put_map(i, map, value);
			i -= g_size;
		}
	}
}

void	ft_col_row_1(int idx, int **map)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	if (idx < g_size * 2)
	{
		col = idx % g_size;
		if (idx >= g_size)
			row = g_size - 1;
	}
	else
	{
		row = idx % g_size;
		if (idx >= g_size * 3)
			col = g_size - 1;
	}
	ft_put_map((row * g_size) + col, map, g_size);
}
