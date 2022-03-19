/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:27:06 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 15:27:18 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

void	ft_print_map(int	**map)
{
	int	i;
	int	j;

	if (map == 0)
		ft_error();
	else
	{
		i = -1;
		while (++i < g_size)
		{
			j = -1;
			while (++j < g_size)
			{
				ft_putchar(map[i][j] + '0');
				if (j < g_size - 1)
					ft_putchar(' ');
			}
			ft_putchar('\n');
		}
	}
}
