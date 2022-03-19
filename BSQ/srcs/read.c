/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:43:56 by siopark           #+#    #+#             */
/*   Updated: 2022/01/26 21:17:20 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_conlen(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		i++;
		if (input[i] == '\n')
			return (i + 1);
	}
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void	ft_strcat(char *dest, char *src, int *size, int buff_size)
{
	int	i;
	int	j;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < buff_size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	while (j >= 0)
	{
		src[j] = '\0';
		j--;
	}
	dest[i] = '\0';
}

void	escape_loop(int *size, char *input, int buf)
{
	if (*size == buf)
	{
		if (ft_conlen(input) == 0)
		*size = -1;
	}
}

char	*ft_read(int f, int buff_size)
{
	char	*buffer;
	char	*input;
	char	*temp;
	int		size;

	size = 0;
	malloc_char(&buffer, &input, &temp, buff_size);
	input[0] = 0;
	temp[0] = 0;
	while (read(f, buffer, buff_size) && input && temp && size >= 0)
	{
		size += buff_size;
		ft_strcpy(temp, input);
		free(input);
		input = (char *)malloc(sizeof(*input) * (size + 1));
		ft_strcpy(input, temp);
		ft_strcat(input, buffer, &size, buff_size);
		input[size] = '\0';
		free(temp);
		temp = (char *)malloc(sizeof(*temp) * (size + 1));
		escape_loop(&size, input, buff_size);
	}
	free(temp);
	free(buffer);
	return (input);
}
