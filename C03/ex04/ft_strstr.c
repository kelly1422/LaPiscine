/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:19:35 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/12 12:47:44 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str2;
	char	*find2;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			str2 = str;
			find2 = to_find;
			while (*find2)
			{
				str2++;
				find2++;
				if (*find2 == '\0')
					return (str);
				if (*str2 != *find2)
					break ;
			}
		}
		str++;
	}
	return (0);
}
