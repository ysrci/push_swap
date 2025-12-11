# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 10:24:41 by yel-bakk          #+#    #+#              #
#    Updated: 2025/12/11 11:51:12 by yel-bakk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
      ft_utils.c \
      ft_error.c \
      ft_atoi.c \
      ft_split.c \
      ft_nodes.c \
      ft_stor_stac_a.c \
      ft_sort_index.c \
	  ft_sa_sb_ss.c \
	  ft_pa_pb.c \
	  ft_rra_rrb_rrr.c \
	  ft_ra_rb_rr.c \
	  ft_sort.c \
	  ft_sort_larg.c \
	  ft_utils_sort_larg_1.c \
	  ft_utils_sort_larg_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
