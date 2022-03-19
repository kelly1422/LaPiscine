/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:29:55 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 04:29:55 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_get_line(char *buf, int fd)
{
	int	i_len;

	i_len = 0;
	read(fd, (void *)buf, 1);
	while (*buf != '\n')
	{
		buf++;
		i_len = i_len + read(fd, (void *)buf, 1);
	}
	*buf = 0;
	if(!i_len)
		return (-1); //찾고 있는 해당 라인이
	if (i_len == 1 && *buf == '\0')
		return (0);
	return (i_len);
}
void	ft_get_value(char *buf)
{
    int     i_idx;
    int     len;

    i_idx = 0;
    len = 0;
	buf++;
    while (*buf != ':')
    {
        buf++;
    }
    if (*buf == ':')
    {
        buf++;
        trim(buf);
    }
    else
    {
        ft_print_error(DICT_ERR);
    }
}

int    ft_has_key(int fd, char *key)
{
    int     idx;
    char    buf[1024] = "";
    while (ft_get_line(buf, fd) != -1)
    {
        idx = 0;
        while (buf[idx] && key[idx] && buf[idx] == key[idx])
        {
            idx++;
        }
        if (key[idx] == '\0' && (buf[idx] == ' ' || buf[idx] == ':'))
        {
			ft_get_value(buf);
			return (1);
        }
    }
	return (0);
	ft_print_error(DICT_ERR);
}

void	ft_make_digits(char **zeros, int size)
{
	char    *str;
    int     i;
    i = 0;
    str = (char *)malloc(sizeof(char) * (size + 2));
    if ( size > 1)
        str[i++] = '1';
    while (i <= size)
        str[i++] = '0';
    str[i] = '\0';
    *zeros = str;
}

int	ft_parse(char *key)
{
	int		fd;

	fd = open("./numbers.dict", O_RDONLY);
	if (fd != -1)
	{
		if (!ft_has_key(fd, key))
		{
			ft_print_error(DICT_ERR);
			return (0);
		}
		close(fd);
	}
	return (1);
}

int	ft_parse_3(char *key, char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		if (!ft_has_key(fd, key))
		{
			ft_print_error(DICT_ERR);
			return (0);
		}
		close(fd);
	}
	return (1);
}

int	ft_parse_100(char *s_num)
{
	char	s_100[2];

	if (s_num[0] != '0')
	{
		s_100[0] = s_num[0];
		s_100[1] = 0;
		if (!ft_parse(s_100))
			return (0);
		if (!ft_parse("100"))
			return (0);
	}
	return (1);
}

int	ft_parse_10(char *s_num)
{
	char	s_10[3];

	if (s_num[0] != '0')
	{
		s_10[0] = s_num[0];
		s_10[1] = '0';
		s_10[2] = 0;
		if (!ft_parse(s_10))
			return (0);
	}
	return (1);
}

int	ft_parse_10_1(char *s_num)
{
	char	s_10[3];

	s_10[0] = s_num[0];
	s_10[1] = s_num[1];
	s_10[2] = 0;
	if (!ft_parse(s_10))
		return (0);
	return (1);
}

int	ft_parse_1(char *s_num)
{
	char	s_1[2];

	if (s_num[0] != '0')
	{
		s_1[0] = s_num[0];
		s_1[1] = 0;
		if (!ft_parse(s_1))
			return (0);
	}
	return (1);
}

void print_level(char *str)
{
	if(str[0] == '1')
	{
		ft_parse(str);
	}
}
int	ft_print_3_digit(char *s_num, int i_size, int i_digits)
{
	char	*s_digits;

	s_digits = 0;
	if (i_size == 3){
		if(!(ft_parse_100(s_num)))
			return (0);
		s_num++;
	}
	if (i_size >= 2 && s_num[0] != '1')
	{
		if(!(ft_parse_10(s_num)))
			return (0);
		s_num++;
		if (!ft_parse_1(s_num))
		return (0);
	}
	else
		ft_parse_10_1(s_num);
	ft_make_digits(&s_digits, i_digits);
	print_level(s_digits);
	free(s_digits);
	return (1);
}