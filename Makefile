# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 10:31:22 by yel-bakk          #+#    #+#              #
#    Updated: 2025/12/22 15:15:25 by yel-bakk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/main.c \
      src/ft_check_args.c \
      src/ft_split.c \
      src/ft_atoi.c \
      src/ft_build_stack_a.c \
      src/ft_utils_linked_list.c \
      src/ft_sort_mini.c \
      src/ft_sa_sb_ss.c \
      src/ft_pa_pb.c \
      src/ft_ra_rb_rr.c \
      src/ft_rra_rrb_rrr.c \
      src/ft_sort_larg.c \
      src/ft_cost_utils.c \
      src/ft_target_utils.c \
      src/ft_rotate_utils.c \
      src/ft_sort_index.c

SRC_BONUS = bonus/main_bonus.c \
	    bonus/ft_sort_bonus.c \
	    bonus/get_next_line.c \
	    bonus/get_next_line_utils.c \
	    src/ft_check_args.c \
	    src/ft_split.c \
	    src/ft_atoi.c \
	    src/ft_build_stack_a.c \
	    src/ft_utils_linked_list.c \
	    src/ft_ra_rb_rr.c \
	    src/ft_pa_pb.c \
	    src/ft_sa_sb_ss.c \
	    src/ft_rra_rrb_rrr.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) 
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean  re
