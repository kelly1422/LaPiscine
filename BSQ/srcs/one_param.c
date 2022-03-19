/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:43:22 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:24:44 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	one_init_map_info(char *input, t_map_info *info)
{
	int	len;

	len = 0;
	while (input[len] != '\n')
		len++;
	if (len < 4)
		return (0);
	if (is_wrong(input[len - 1], input[len - 2], input[len - 3], info))
		return (0);
	if (!ft_atoin(input, len - 3))
		return (0);
	else
		info->y = ft_atoin(input, len - 3);
	return (1);
}

int	one_valid_row(char *input, t_map_info *info)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*input != '\n')
		input++;
	while (*(++input) != '\0')
	{
		if (*input == '\n')
		{
			if (i++ == 0)
				info->x = len;
			else if (len != info->x)
				return (0);
			len = 0;
		}
		else if (!is_input(*input, info))
			return (0);
		else
			len += 1;
	}
	if (i != info->y)
		return (0);
	return (info->x);
}

void	one_init_map(char **map, char *input, t_map_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (*input != '\n')
		input++;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			map[i][j] = *(++input);
			j += 1;
		}
		map[i][j] = 0;
		input++;
		i += 1;
	}
}
