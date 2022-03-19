/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:06:43 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 22:03:11 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	map_info_init(int fd, t_map_info *info)
{
	char	word[14];
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (i < 14)
		word[i++] = 0;
	while (read(fd, &word[len], 1) > 0)
	{
		if (word[len] == '\n')
			break ;
		len += 1;
	}
	word[len] = 0;
	if (len < 4)
		return (0);
	if (is_wrong(word[len - 1], word[len - 2], word[len - 3], info))
		return (0);
	if (!ft_atoin(word, len - 3))
		return (0);
	else
		info->y = ft_atoin(word, len - 3);
	return (1);
}

int	is_input(char c, t_map_info *info)
{
	if (!(c == info->obs || c == info->empty))
		return (0);
	return (1);
}

int	valid_row(int fd, t_map_info *info)
{
	char	c;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (i++ == 0)
				info->x = len;
			else if (len != info->x)
				return (0);
			len = 0;
		}
		else if (!is_input(c, info))
			return (0);
		else
			len += 1;
	}
	if (i != info->y)
		return (0);
	return (info->x);
}
