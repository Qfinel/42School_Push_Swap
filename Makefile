# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 11:57:19 by jtsizik           #+#    #+#              #
#    Updated: 2022/11/09 13:13:04 by jtsizik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = 	push_swap.c \
		sort_big.c \
		sort_small.c \
		sorting.c \
		utils.c \
		sort_real_big.c \
		printf/ft_printf.c \
		printf/ft_hex.c \
		printf/ft_printf_utils.c \
		printf/ft_uint.c \
		operations/swap.c \
		operations/push.c \
		operations/rev_rotate.c \
		operations/rotate.c \
		libft/ft_atoi.c \
		libft/ft_isdigit.c \
		libft/ft_calloc.c \
		libft/ft_bzero.c \
		libft/ft_itoa.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c

INCS = 	push_swap.h \
		libft/libft.h \
		printf/ft_printf.h

OBJS = 	push_swap.o \
		sort_big.o \
		sort_small.o \
		sorting.o \
		utils.o \
		sort_real_big.o \
		ft_printf.o \
		ft_hex.o \
		ft_printf_utils.o \
		ft_uint.o \
		swap.o \
		push.o \
		rev_rotate.o \
		rotate.o \
		ft_atoi.o \
		ft_isdigit.o \
		ft_calloc.o \
		ft_bzero.o \
		ft_itoa.o \
		ft_putstr_fd.o \
		ft_split.o

$(NAME):
	cc -c -Wall -Wextra -Werror $(SRCS) -I $(INCS)
	cc $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



