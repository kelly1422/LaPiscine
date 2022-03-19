/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:03:34 by siopark           #+#    #+#             */
/*   Updated: 2022/01/27 09:50:29 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	total_process(char *file, int fd, t_map_info *info)
{
	char	**map;

	if (valid_row(fd, info))
	{
		map = make_map(info);
		init_map(map, file, info);
		solution(map, info);
	}
	else
		write(2, "map error\n", 10);
}

void	one_total_process(char *input, t_map_info *info)
{
	char	**map;

	if (one_valid_row(input, info))
	{
		map = make_map(info);
		one_init_map(map, input, info);
		solution(map, info);
	}
	else
		write(2, "map error\n", 10);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			fd;
	t_map_info	info;
	char		*input;

	if (argc == 1)
	{
		input = ft_read(0, BUFF);
		if (one_init_map_info(input, &info))
			one_total_process(input, &info);
		else
			write(2, "map error\n", 10);
	}
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (map_info_init(fd, &info))
			total_process(argv[i], fd, &info);
		else
			write(2, "map error\n", 10);
		close(fd);
		if (i != argc - 1)
			write(1, "\n", 1);
	}
}
