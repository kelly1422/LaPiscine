/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:35:43 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/24 14:53:52 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*num;
	int	val;

	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	num = *range;
	val = min;
	while (val < max)
	{
		*num = val;
		num++;
		val++;
	}
	return (max - min);
}
