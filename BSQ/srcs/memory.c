/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:15:29 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:17:45 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	memory_free_dp(int **array, t_map_info *info)
{
	int	i;

	i = -1;
	while (++i < info->y)
		free(array[i]);
	free(array);
}

void	memory_free_map(char **array, t_map_info *info)
{
	int	i;

	i = -1;
	while (++i < info->y)
		free(array[i]);
	free(array);
}

void	malloc_char(char **buffer, char **input, char **temp, int buff_size)
{
	char	*a;
	char	*b;
	char	*c;

	a = (char *)malloc(sizeof(char) * (buff_size + 1));
	b = (char *)malloc(sizeof(char) * 1);
	c = (char *)malloc(sizeof(char) * 1);
	*buffer = a;
	*input = b;
	*temp = c;
}
