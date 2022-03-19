/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonychoi <wonychoi@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:24:25 by wonychoi          #+#    #+#             */
/*   Updated: 2022/01/22 00:24:25 by wonychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
#define RUSH_H

enum e_err
{
    ERR = 0,
    DICT_ERR
};

// Header File
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // remove...


// Declare Func
// argc.c
int	ft_is_valid_num(char *str);
void ft_split_param(char *str);
// error.c
void    ft_print_error(int err);
//parse.c
int	ft_get_line(char *buf, int fd);
char	*ft_get_key(char *buf);
void    ft_get_value(char *buf);
int	ft_has_key(int fd, char *key);
void	ft_make_digits(char **s_digit, int i_size);
int	ft_parse(char *key);
int	ft_print_3_digit(char *s_num, int i_size, int i_digits);
//func.c
void    ft_putchar(char c);
void    ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_parse_3(char *key, char *str);
void    trim(char *buf);

#endif