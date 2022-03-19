/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 02:34:10 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 02:34:10 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_is_valid_num(char *str)
{
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
			return (0);
		str++;
	}
	return (1);
}

void ft_split_param(char *str)
{
	int     i_len;
    int     i_size;
    char    *ptr;

    ptr = str;
    i_len = ft_strlen(str);  
    i_size = (i_len - 1) / 3;
    if(i_len % 3 != 0)
    {
        ft_print_3_digit(ptr, i_len % 3, i_size * 3);
        ptr = ptr + (i_len % 3);
        i_size--;
    }
    while (i_size >= 0)
    {
        ft_print_3_digit(ptr, 3, i_size * 3);
        i_size--;
        ptr = ptr + 3;
    }
}