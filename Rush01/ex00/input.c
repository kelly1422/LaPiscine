/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:51:18 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 19:42:49 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_num(char c)
{	
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	else if (c >= '1' && c <= '9')
		return (1);
	return (2);
}

int	word_count(char *str)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_num(str[i]) == 0)
			i++;
		if (str[i] == '\0')
			break ;
		if (is_num(str[i]) == 1)
		{
			if (is_num(str[i + 1]) == 0 || str[i + 1] == '\0')
				cnt++;
			else if (is_num(str[i + 1]) != 0)
				return (0);
		}
		else if (is_num(str[i]) == 2)
			return (0);
		i++;
	}
	return (cnt);
}

int	get_mapsize(int word_size)
{
	int	map_size;

	map_size = 0;
	if (word_size == 16)
		map_size = 4;
	else if (word_size == 20)
		map_size = 5;
	else if (word_size == 24)
		map_size = 6;
	else if (word_size == 28)
		map_size = 7;
	else if (word_size == 32)
		map_size = 8;
	else if (word_size == 36)
		map_size = 9;
	else
		return (0);
	return (map_size);
}

int	ft_count(int	*input)
{
	int	cnt;

	cnt = 0;
	while (input[cnt] >= 1 && input[cnt] <= 9)
		cnt++;
	return (cnt);
}

int	*ft_split(char *str)
{
	int	int_idx;
	int	word_size;
	int	idx;
	int	*num;

	word_size = word_count(str);
	if (get_mapsize(word_size) == 0)
		return (0);
	num = (int *)malloc(sizeof(int) * (word_size));
	if (!num)
		return (0);
	int_idx = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (is_num(str[idx]) == 1)
			num[int_idx++] = str[idx] - '0';
		idx++;
	}	
	return (num);
}
