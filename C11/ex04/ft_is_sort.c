/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:05:56 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/27 18:24:37 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			flag = 0;
			break ;
		}
		i++;
	}
	i = -1;
	if (flag == 0)
	{
		while (++i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		}
		flag = 1;
	}
	return (flag);
}
