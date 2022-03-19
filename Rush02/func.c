/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:45:15 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 04:45:15 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str++);
    }
}

int	ft_strlen(char *str)
{
	int	i_len;

	i_len = 0;
	while (str[i_len])
		i_len++;
	return (i_len);
}

void    trim(char *buf)
{
	char	re[1204];
	int		flag;
	int		idx;

	flag = 0;
	idx = 0;
	while (*buf)
	{
		if (*buf == ' ' && flag == 1)
		{
			re[idx++] = ' ';
			flag = 0;
		}
		if (*buf != ' ')
		{
			flag = 1;
			re[idx++] = *buf;
		}
		buf++;
	}
	re[idx] = '\0';
    int i =0;
    while (i < idx - 1)
    {
        write(1, &re[i], 1);
        i++;
    }
    write(1, " ", 1);
}