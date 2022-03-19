/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:07:08 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/11 15:52:37 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_index;
	unsigned int	after_len;
	unsigned int	i;

	d_index = 0;
	after_len = 0;
	i = 0;
	while (dest[d_index])
		d_index++;
	while (src[after_len])
		after_len++;
	if (size <= d_index)
		after_len += size;
	else
		after_len += d_index;
	while (src[i] && d_index + 1 < size)
		dest[d_index++] = src[i++];
	dest[d_index] = '\0';
	return (after_len);
}
