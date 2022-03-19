/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:45:25 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 19:41:05 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	malloc_for_map(int	***map)
{
	int	i;
	int	**map_size;

	map_size = (int **)malloc(sizeof(int *) * g_size);
	if (!map_size)
		return (0);
	i = -1;
	while (++i < g_size)
	{
		map_size[i] = (int *)malloc(sizeof(int) * g_size);
		if (!map_size[i])
			return (0);
	}
	*map = map_size;
	return (1);
}

void	malloc_for_free(int	*input, int	**map)
{
	int	i;

	i = -1;
	free(input);
	while (++i < g_size)
	{
		free(map[i]);
	}
	free(map);
}

int	main(int	argc, char	*argv[])
{
	int	*input;
	int	**map;

	map = NULL;
	if (argc != 2 && ft_error())
		return (0);
	input = ft_split(argv[1]);
	if (input == 0)
		return (0);
	g_size = get_mapsize(ft_count(input));
	malloc_for_map(&map);
	if (map == NULL)
		return (0);
	ft_total_process(input, map);
	malloc_for_free(input, map);
	return (0);
}
