# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 01:24:56 by afahs             #+#    #+#              #
#    Updated: 2025/05/30 10:47:45 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c \
	  pf_utils.c \

OBJ = $(SRC:.c=.o)

CC = cc
RM = rm -f
AR = ar rc
RN = ranlib

%.o: %.c
	$(CC) $(CFLAG) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(RN) $(NAME)

all: $(NAME)

clean:
			$(RM) $(OBJ)
			
fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re