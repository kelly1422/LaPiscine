/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:15:04 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/19 11:51:08 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (rec(index - 1) + rec(index - 2));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (rec(index));
}
