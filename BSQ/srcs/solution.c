/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:57:56 by siopark           #+#    #+#             */
/*   Updated: 2022/01/27 09:32:40 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	judge_dp(int **dp, int i, int j, t_map_info *info)
{
	int	ret;

	ret = 0;
	if (check_pos(i, j))
	{
		dp[i][j] = min_calc(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
		if (dp[i][j] > info->max)
		{
			info->max = dp[i][j];
			info->c_y = i;
			info->c_x = j;
		}
	}
	else
	{
		dp[i][j] = 1;
		if (dp[i][j] > info->max)
		{
			info->max = dp[i][j];
			info->c_y = i;
			info->c_x = j;
		}
	}
}

void	iter_map(char **map, t_map_info *info)
{
	int	**dp;
	int	i;
	int	j;

	dp = create_dp_array(info);
	info->max = 0;
	i = -1;
	while (++i < info->y)
	{
		j = -1;
		while (++j < info->x)
		{
			if (map[i][j] == info->empty)
				judge_dp(dp, i, j, info);
		}
	}
	memory_free_dp(dp, info);
}

void	calc_squre(char **map, t_map_info *info)
{
	int	i;
	int	j;

	i = info->c_y - info->max;
	while (++i <= info->c_y)
	{
		j = info->c_x - info->max;
		while (++j <= info->c_x)
			map[i][j] = info->full;
	}
}

void	solution(char **map, t_map_info *info)
{
	iter_map(map, info);
	calc_squre(map, info);
	print_array(map, info);
	memory_free_map(map, info);
}
