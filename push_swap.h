/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:35:15 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 11:53:08 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}					t_node;

//ft_utils
void	ft_skip_spaces(char **s);
int		ft_get_num_len(char *s);
int		ft_check_sign(char c, int *sign);
int		ft_isdigit(char c);
int		ft_check_digit_range(long num, int sign);

//ft_error
void	ft_error_exit(void);
void	ft_check_args(int argc, char **argv);
int		ft_is_valid_num(char *s, int len);
int		ft_is_duplicate(t_node *stack, t_node **stack_a);

//functions help
int		ft_atoi(char *s);
char	**ft_split(char *s);

//functions stack a
void	ft_fill_stack_a(t_node **stack, int argc, char **argv);
void	ft_free_split(char	**split);
void	ft_exit_error(t_node **stack, char **array);
void	ft_free_split(char	**split);
void	ft_free_array(char	**array);
void	ft_free_stack(t_node **stack);

//function linked list
void	ft_add_back(t_node **stack, t_node *new);
t_node	*ft_new_node(int value);
int		ft_stack_size(t_node *stack);

//sort index
int		ft_is_sorted(t_node *stack);
void	ft_sort_index(t_node *stack);

//The Rulessss
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);

//Functions sort
void	ft_sort_two(t_node **a);
void	ft_sort_three(t_node **a);
int		*ft_find_lis(t_node *stack, int size, int *lis_len);
void	ft_push_out_lis(t_node **a, t_node **b, int *lis, int lis_len);
void	ft_sort_large(t_node **a, t_node **b);

//utils_sort_larg_1
void	ft_assign_index(t_node *stack);
void	ft_update_positions(t_node *stack);
void	ft_calculate_cost(t_node *a, t_node *b);
void	ft_execute_cheapest_move(t_node **a, t_node **b);
void	ft_final_rotation(t_node **a);

//utils_sort_larg_2
int ft_find_target_pos(t_node *a, int b_index);
void ft_move_to_top(t_node **a, t_node **b, t_node *node);
int ft_find_min_val_pos(t_node *a);


#endif
