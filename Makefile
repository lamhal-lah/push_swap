# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 17:10:08 by lamhal            #+#    #+#              #
#    Updated: 2024/04/23 10:11:17 by lamhal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_split.c stack.c parssing.c push_swap.c switch.c push.c rotat.c revrotat.c \
	utils.c pushback.c sort.c

OBJ = $(SRC:.c=.o)

SRC_B = bonus/ft_split_bonus.c bonus/push_bonus.c bonus/checker_bonus.c  \
	bonus/parss_bonus.c bonus/rotat_bonus.c bonus/revrotat_bonus.c bonus/switch_bonus.c \
	bonus/stack_bonus.c bonus/utils_bonus.c bonus/getn/get_next_line_utils.c bonus/getn/get_next_line.c \
	bonus/process_bonus.c
	

OBJ_B = $(SRC_B:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(OBJ_B)
	$(CC) -o $@ $^ $(CFLAGS)
	
bonus/%.o: bonus/%.c  bonus/checker_bonus.h
	$(CC) -o $@ -c $< $(CFLAGS)

%.o: %.c push_swap.h 
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -f $(OBJ) $(OBJ_B)
fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean