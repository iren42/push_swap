# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iren <iren@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 17:41:07 by iren              #+#    #+#              #
#    Updated: 2022/03/29 14:18:42 by iren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

HEADER	= include/push_swap.h

LIBFT	= libft

DIR_SOURCES	= src/

SOURCES		=	push_swap.c \
				init.c \
				utils_stack.c \
				errors.c \
			  	ra.c	\
			  	rra.c	\
			  	pa.c	\
			  	sa.c	\
				mini_sort.c \
				getset_tint.c

SRCS	=	$(addprefix $(DIR_SOURCES), $(SOURCES))

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror 

RM		= rm -f

all		: $(NAME)

%.o		: %.c $(HEADER)
		$(CC) $(CFLAGS) -Iinclude -g -c $< -o $@

$(NAME) : $(OBJS) $(HEADER) $(LIBFT)
		make -C $(LIBFT)
		make bonus -C $(LIBFT)
	  $(CC) -o $@ $(OBJS) libft/libft.a
	

norm	:
		norminette $(SRCS)
		norminette -R CheckDefine $(HEADER)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean	: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re		: fclean all

.PHONY:	all clean fclean re
