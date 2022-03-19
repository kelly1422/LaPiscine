# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libt_creator.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngkki <youngkki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:42:12 by youngkki          #+#    #+#              #
#    Updated: 2022/01/27 11:20:01 by youngkki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rcs libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
