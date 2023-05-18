# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 11:54:57 by zouaraqa          #+#    #+#              #
#    Updated: 2023/05/18 11:01:27 by zouaraqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = minishell
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = 	parsing_test.c \
		linked_list.c \
		ft_split.c \
		ft_substr.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -fsanitize=address -g -lreadline $^ -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all