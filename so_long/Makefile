# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 03:19:33 by afahs             #+#    #+#              #
#    Updated: 2025/07/04 20:03:59 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRCS = main.c \
	   gnl/get_next_line.c \
	   gnl/get_next_line_utils.c\
	   utils/check_path.c\
	   utils/read_utils.c\
	   utils/check_utils_one.c\
	   utils/exit_utils.c\
	   utils/build_window.c\
	   utils/player_utils.c\
	   utils/display_utils.c\
	   utils/render_utils.c\

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(MLX_DIR)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
