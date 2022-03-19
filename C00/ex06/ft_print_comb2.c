/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:02:35 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/09 14:04:50 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add_print_num(char *num_arr, int first_index, int sec_index)
{
	write(1, num_arr, 7);
	if (num_arr[sec_index] == '9')
	{
		num_arr[first_index]++;
		num_arr[sec_index] = '0';
	}
	else
	{
		num_arr[sec_index]++;
	}
}

void	ft_print_comb2(void)
{
	char	num_arr[7];

	num_arr[0] = '0';
	num_arr[1] = '0';
	num_arr[2] = ' ';
	num_arr[5] = ',';
	num_arr[6] = ' ';
	while (!(num_arr[0] == '9' && num_arr[1] == '8'))
	{
		num_arr[3] = num_arr[0];
		num_arr[4] = num_arr[1] + 1;
		if (num_arr[1] == '9')
		{
			num_arr[3]++;
			num_arr[4] = '0';
		}
		while (!(num_arr[3] == '9' && num_arr[4] == '9'))
		{
			add_print_num(num_arr, 3, 4);
		}
		add_print_num(num_arr, 0, 1);
	}
	write(1, "98 99", 5);
}
