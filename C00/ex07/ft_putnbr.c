/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:02:50 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/09 14:00:57 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_print(int nb)
{
	char	c;

	if (nb == 0)
		return ;
	recursive_print(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		recursive_print(-(nb / 10));
		c = '0' - nb % 10;
	}	
	else
	{
		recursive_print(nb / 10);
		c = '0' + nb % 10;
	}
	write(1, &c, 1);
}
