/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 01:37:53 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 01:37:53 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void    ft_print_error(int err)
{
    if (err == ERR)
        ft_putstr("Error\n");
    else if (err == DICT_ERR)
        ft_putstr("Dict Error\n");   
}