/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:23 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/27 18:22:49 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (i < length)
	{
		if (f(tab[i++]) != 0)
			cnt++;
	}
	return (cnt);
}
