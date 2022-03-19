/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:27:16 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/26 15:16:48 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	wordcount(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			cnt++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
			continue ;
		}
		i++;
	}
	return (cnt);
}

int	wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!is_charset(str[i], charset) && str[i])
		i++;
	return (i);
}

void	ft_strncpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		idx;
	int		word;

	i = 0;
	idx = 0;
	result = (char **)malloc(sizeof(char *) * (wordcount(str, charset) + 1));
	if (!result)
		return (0);
	while (str[i] && idx < wordcount(str, charset))
	{
		if (!is_charset(str[i], charset))
		{
			word = wordlen(&str[i], charset);
			result[idx] = (char *)malloc(sizeof(char) * word + 1);
			ft_strncpy(result[idx++], &str[i], word);
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		i++;
	}
	result[idx] = 0;
	return (result);
}
