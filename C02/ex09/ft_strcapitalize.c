/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 21:18:30 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/10 20:07:52 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	small(char c)
{
	if (97 <= c && c <= 122)
		return (1);
	return (0);
}

int	big(char c)
{
	if (65 <= c && c <= 90)
		return (1);
	return (0);
}

int	other(char c)
{
	if (number(c))
		return (0);
	if (big(c))
		return (0);
	if (small(c))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	while (str[i])
	{
		if (i == 0 || other(str[i - 1]))
			first = 1;
		else
			first = 0;
		if (first && small(str[i]))
			str[i] -= 32;
		else if (!first && big(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
