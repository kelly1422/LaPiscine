/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:11:08 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/24 14:40:56 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*convert_str(int nbr, int baselen, char *base);

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 12))
		return (1);
	return (0);
}

unsigned int	check_base(char *base)
{
	char	*ptr;
	char	*base_cmp;
	int		i;

	i = 0;
	ptr = base;
	while (*ptr)
	{
		base_cmp = ptr + 1;
		if (*ptr == '+' || *ptr == '-' || is_space(*ptr))
			return (0);
		while (*base_cmp)
		{
			if (*ptr == *base_cmp)
				return (0);
			base_cmp++;
		}
		ptr++;
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

int	get_idx(char c, int len, char *base)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_atoi_base(char *nbr, char *base, int baselen, int *n)
{
	int	result;
	int	sign;
	int	idx;

	sign = 1;
	result = 0;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
		if (*nbr++ == '-')
			sign = sign * -1;
	while (*nbr)
	{
		idx = get_idx(*(nbr++), baselen, base);
		if (idx == -1)
			break ;
		result = baselen * result + idx;
	}
	*n = (sign * result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_from_len;
	int		base_to_len;
	char	*result;

	num = 0;
	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	if (base_from_len > 0 && base_to_len > 0)
	{
		ft_atoi_base(nbr, base_from, base_from_len, &num);
		result = convert_str(num, base_to_len, base_to);
		return (result);
	}
	else
		return (0);
}
