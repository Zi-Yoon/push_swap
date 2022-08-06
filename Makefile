# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 10:20:15 by byan              #+#    #+#              #
#    Updated: 2022/08/07 05:15:31 by byan             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= settings.c \
			push_swap.c \
			basic_push.c \
			basic_rotate.c \
			basic_r_rotate.c \
			basic_swap.c \
			make_node.c \
			make_node_utils.c \
			set_a_location.c \
			sort_rotate.c \
			sort_start.c \
			stack_rotate.c

OBJS		= $(SRCS:%.c=%.o)
LIBC		= ar rc
FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		gcc $(FLAGS) -c -g $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re bonus