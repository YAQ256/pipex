# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 15:24:35 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/13 16:20:11 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

HEADER = pipex.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
LIB = ./src/pipex.h
LIB_BONUS = ./src_bonus/pipex_bonus.h
SRC_PATH = ./src/
SRC_BONUS_PATH = ./src_bonus/
OBJ_FL = objs
OBJB_FL = objs_bonus

SRC =	errors.c\
		files.c\
		main.c\
		pipex.c

SRC_BONUS =	errors_bonus.c\
			files_bonus.c\
			main_bonus.c\
			pipex_bonus.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft $(NAME)

make_libft:
	@make all -C ./libft

bonus: make_libft $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -I $(LIB) -o $(NAME)
	@echo "all compiled"

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJS_BONUS) -I $(LIB_BONUS) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@echo "All Clean"

re: fclean all

reb: fclean all

.PHONY: all clean fclean re bonus