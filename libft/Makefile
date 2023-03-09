# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 17:17:25 by cyacoub-          #+#    #+#              #
#    Updated: 2023/03/09 17:55:53 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRC =	ft_strncmp.c\
		ft_strlen.c\
		ft_strjoin.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_strchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_bzero.c\
		ft_memset.c\
		ft_strnstr.c\
		#get_next_line.c\
		#get_next_line_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean