# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afahs <afahs@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 01:24:56 by afahs             #+#    #+#              #
#    Updated: 2025/05/24 07:39:21 by afahs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memcpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_calloc.c \
	  ft_substr.c \
	  ft_strlcpy.c \
	  ft_striteri.c \
	  ft_split.c \

B_SRC = ft_lstnew.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		
OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

CC = cc
RM = rm -f
AR = ar rc
RN = ranlib

%.o: %.c
	$(CC) $(CFLAG) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(RN) $(NAME)

bonus: $(B_OBJ)
			$(AR) $(NAME) $(B_OBJ)
			$(RN) $(NAME)

all: $(NAME)

clean:
			$(RM) $(OBJ) $(B_OBJ)
			
fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re