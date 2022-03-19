/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siopark <siopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:04:29 by siopark           #+#    #+#             */
/*   Updated: 2022/01/27 10:28:48 by siopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF 1000000

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		x;
	int		y;
	int		max;
	int		c_x;
	int		c_y;
	char	obs;
	char	full;
	char	empty;
}	t_map_info;

int		map_info_init(int fd, t_map_info *info);
int		is_wrong(unsigned char a, unsigned char b, \
		unsigned char c, t_map_info *info);
int		ft_atoin(char *str, int size);
int		check_pos(int x, int y);
int		min_calc(int row, int col, int diag);
void	total_process(char *file, int fd, t_map_info *info);
int		valid_row(int fd, t_map_info *info);
int		is_input(char c, t_map_info *info);
char	**make_map(t_map_info *info);
void	init_map(char **map, char *file, t_map_info *info);
void	print_array(char **map, t_map_info *info);
void	ft_putchar(char c);
void	solution(char **map, t_map_info *info);
void	calc_squre(char **map, t_map_info *info);
void	iter_map(char **map, t_map_info *info);
void	judge_dp(int **dp, int i, int j, t_map_info *info);
int		**create_dp_array(t_map_info *info);
void	memory_free_dp(int **array, t_map_info *info);
void	memory_free_map(char **array, t_map_info *info);
void	malloc_char(char **buffer, char **input, char **temp, int buff_size);

void	one_total_process(char *input, t_map_info *info);
int		one_init_map_info(char *input, t_map_info *info);
int		one_valid_row(char *input, t_map_info *info);
void	one_init_map(char **map, char *input, t_map_info *info);

void	ft_strcpy(char *dest, char *src);
void	ft_strcat(char *dest, char *src, int *size, int buff_size);
void	escape_loop(int *size, char *input, int buf);
char	*ft_read(int f, int buff_size);
int		ft_conlen(char *input);
#endif