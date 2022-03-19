/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:34:10 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:53:33 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(char **map, t_map_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->y)
	{
		j = -1;
		while (++j < info->x)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}
