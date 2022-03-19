/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:46:14 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 19:38:49 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	notsame_check(int	idx, int	**map)
{
	int	row;
	int	col;
	int	i;

	i = -1;
	row = idx / g_size;
	col = idx % g_size;
	while (++i < g_size)
	{
		if (i == col)
			continue ;
		if (map[row][i] == map[row][col])
			return (0);
	}
	i = -1;
	while (++i < g_size)
	{
		if (i == row)
			continue ;
		if (map[i][col] == map[row][col])
			return (0);
	}
	return (1);
}

int	**ft_last_process(int	idx, int	*input, int	**map)
{
	int	i;

	if (idx == g_size * g_size)
		return (ft_check(input, map));
	i = -1;
	while (++i < g_size)
	{
		if (map[idx / g_size][idx % g_size] != 0)
			return (ft_last_process(idx + 1, input, map));
		ft_put_map(idx, map, i + 1);
		if (notsame_check(idx, map))
		{
			if (i % g_size == g_size - 1
				&& !(middle_row_check(i / g_size, input, map)))
			{
				map[idx / g_size][idx % g_size] = 0;
				continue ;
			}
			if (ft_last_process(idx + 1, input, map))
				return (map);
		}
		map[idx / g_size][idx % g_size] = 0;
	}
	return (0);
}

int	middle_row_check(int idx, int *input, int **map)
{
	if (input[g_size * 2 + idx] != ft_row_count(idx, map, LEFT))
		return (0);
	if (input[g_size * 3 + idx] != ft_row_count(idx, map, RIGHT))
		return (0);
	return (1);
}

void	ft_total_process(int	*input, int	**map)
{
	int	i;
	int	j;

	if (input == 0)
	{
		ft_print_map(0);
		return ;
	}
	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			map[i][j] = 0;
		}
	}
	ft_first_process(input, map);
	ft_print_map(ft_last_process(0, input, map));
}

void	ft_put_map(int	idx, int	**map, int	value)
{
	map[idx / g_size][idx % g_size] = value;
}
