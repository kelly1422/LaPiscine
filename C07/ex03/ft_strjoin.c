/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:39:47 by wokim             #+#    #+#             */
/*   Updated: 2022/01/24 14:55:27 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

char	*strcat2(char *dest, char *src1, char *src2)
{
	dest = ft_strcat(dest, src1);
	dest = ft_strcat(dest, src2);
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	char	*ptr;
	int		sum;
	int		i;

	if (size == 0)
	{
		result = ((char *)malloc(1));
		result[0] = 0;
		return (result);
	}
	sum = 0;
	i = 0;
	while (i < size)
		sum += ft_strlen(strs[i++]);
	i = sum + (size - 1) * ft_strlen(sep) + 1;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (0);
	ptr = ft_strcat(result, strs[0]);
	i = 1;
	while (i < size)
		ptr = strcat2(ptr, sep, strs[i++]);
	*ptr = 0;
	return (result);
}
