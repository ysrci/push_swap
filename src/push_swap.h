/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:39 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:56:17 by yel-bakk         ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}					t_node;

//Check args
void	ft_exit_error(void);
void	ft_check_args(int argc, char **argv);
char	**ft_split(char *s);
long	ft_atoi(char *str);

//Functions liked list
t_node	*ft_new_node(int value);
void	ft_add_back(t_node **stack, t_node *new);
int		ft_stack_size(t_node *stack);
void	ft_free_stack(t_node **stack);
void	ft_has_duplicat(t_node	**stack);
void	ft_is_sort(t_node **stack);
void	ft_sort_index(t_node *stack);

//Build stack A
t_node	*ft_build_stack_a(int argc, char **argv);

//Sort Function
void	ft_sort_larg(t_node **a, t_node **b);
void	ft_sort_three(t_node **a);
void	ft_find_cheapest(t_node *a, t_node *b, int *cost_a, int *cost_b);
void	ft_do_rotations(t_node **a, t_node **b, int *cost_a, int *cost_b);
int		ft_get_target_pos(t_node *a, int b_index);
int		ft_get_position(t_node *stack, int index);
int		ft_get_min_index(t_node *stack);
int		ft_abs(int n);
void	ft_sort_two(t_node **a);
void	ft_sort_five(t_node **a, t_node **b);

//The Rulessss
void	p_no(t_node **stack_a, t_node **stack_b);
void	r_no(t_node **stack);
void	rr_no(t_node **stack_a, t_node **stack_b);
void	rrrev_no(t_node **stack);
void	rrrrev_no(t_node **stack_a, t_node **stack_b);
void	s_no(t_node **stack);
void	ss_no(t_node **stack_a, t_node **stack_b);
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

#endif
