# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 11:37:42 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/08 11:37:43 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#NAME_BONUS = pipex_bonus

HEADER = pipex.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ./src/pipex.h
#LIB_BONUS = ./src/pipex_bonus.h
SRC_PATH = ./src/
#SRC_BONUS_PATH = ./src_bonus/

SRC =

#SRC_BONUS =

SRCS = $(addprefix $(SRC_PATH), $(SRC))
#SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) -o $(NAME)

#$(NAME_BONUS): $(OBJS_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIB_BONUS) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "All Clean"

re: fclean all

reb: fclean all

.PHONY: all clean fclean re bonus