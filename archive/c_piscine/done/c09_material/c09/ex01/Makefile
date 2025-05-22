# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 21:47:59 by afahs             #+#    #+#              #
#    Updated: 2025/05/01 21:48:11 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INCS = includes
NAME = libft.a
LIBC = ar rc
LIBR = ranlib
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJS)
		${LIBC} ${NAME} ${OBJS}
		${LIBR} ${NAME}

all: ${NAME}
	
clean:
		${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)
	
re: fclean all