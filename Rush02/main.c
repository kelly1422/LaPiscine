/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:17:28 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 00:17:28 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

int only_zero(char *str)
{
    if(str[0] == '0' && str[1] == '\0')
        return (1);
    return (0);
}
int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 3)
    {
        ft_print_error(ERR);
        return (0);
    }
    if (argc == 2)
    {
        if (only_zero(argv[1]))
            ft_parse("0");
        else if (!ft_is_valid_num(argv[1]))
        {
            ft_print_error(ERR);
            return (0);
        }
        ft_split_param(argv[1]);
    }
    if (argc == 3)
    {
        ft_parse_3(argv[1], argv[2]);
    }
    return (0);

}
