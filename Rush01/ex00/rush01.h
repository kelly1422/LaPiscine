/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:35:34 by youngkki          #+#    #+#             */
/*   Updated: 2022/01/16 19:39:32 by youngkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# include <stdlib.h>

# define COL 0
# define ROW 1
# define TRUE 1
# define FALSE 0
# define UP 1
# define DOWN -1
# define LEFT 1
# define RIGHT -1

int		g_size;

void	ft_first_process(int *input, int **map);
void	ft_row_max(int idx, int **map);
void	ft_col_max(int idx, int **map);
void	ft_col_row_1(int idx, int **map);

void	ft_put_map(int idx, int **map, int value);
int		**ft_last_process(int idx, int *input, int **map);
void	ft_total_process(int *input, int **map);
int		notsame_check(int	idx, int	**map);
int		middle_row_check(int idx, int *input, int **map);

int		**ft_check(int *input, int **map);
int		ft_col_count(int col_idx, int **map, int dir);
int		ft_row_count(int row_idx, int **map, int dir);

int		is_num(char	c);
int		word_count(char *str);
int		get_mapsize(int word_size);
int		ft_count(int *input);
int		*ft_split(char *str);

void	ft_putchar(char c);
void	ft_print_map(int **map);
int		ft_error(void);
#endif
