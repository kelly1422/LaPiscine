/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:31:02 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:04:58 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**make_map(t_map_info *info)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (info->y + 1));
	if (!map)
		return (0);
	i = 0;
	while (i < info->y)
	{
		map[i] = (char *)malloc(sizeof(char) * info->x + 1);
		if (!map[i])
			return (0);
		i++;
	}
	return (map);
}

void	init_map(char **map, char *file, t_map_info *info)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &c, 1) > 0 && c != '\n')
			continue ;
		while (i < info->y)
		{
			j = 0;
			while (j < info->x)
			{
				read(fd, &c, 1);
				map[i][j] = c;
				j += 1;
			}
			read(fd, &c, 1);
			map[i][j] = 0;
			i += 1;
		}
	}
}

int	**create_dp_array(t_map_info *info)
{
	int	**dp;
	int	i;
	int	j;

	i = -1;
	dp = (int **)malloc(sizeof(int *) * info->y);
	while (++i < info->y)
	{
		dp[i] = (int *)malloc(sizeof(int ) * info->x);
		j = -1;
		while (++j < info->x)
			dp[i][j] = 0;
	}	
	return (dp);
}
