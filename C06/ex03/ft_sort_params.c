/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:09:00 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/19 17:53:48 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

char	**sort(int size, char **b_sort)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (ft_strcmp(b_sort[j], b_sort[j + 1]) > 0)
			{
				tmp = b_sort[j];
				b_sort[j] = b_sort[j + 1];
				b_sort[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (b_sort);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**str;

	i = 1;
	if (argc > 1)
	{
		str = sort(argc - 1, argv);
		while (str[i])
		{
			putstr(str[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
