/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:06:01 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:25:24 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				chunk;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		iter;
}	t_data;

int		*int_input(int argc, char **argv, int *size, int *error);
int		check_sorted(int *tab, int *size);
int		ft_wdcount(char *s, char c);
void	ft_freesplit(char **strs);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str, int *error);
int		*ft_sorted_index(int *tab, int *size);
t_list	*ft_newnode(int value, int index);
t_list	*ft_gotolast(t_list **stack);
void	ft_addnode_back(t_list **stack, t_list*node);
void	ft_freelist(t_list **stack);
int		ft_stack_size(t_list *stack);
t_list	*init_list(int	*tab, int *size);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	re_index(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b, t_data *data);
void	pa(t_list **stack_a, t_list **stack_b, t_data *data);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	clever_rotate(t_list **stack, int nbr);
int		min_stack(t_list **stack);
void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data);
int		leave_main(int *tab, int *size, int *error);
t_data	init_data(int *tab, int *size);
int		size_chunk(t_list *stack, int chunk);
int		midpoint_chunk(t_list *stack, int chunk);
int		nb_topush_a(t_list *stack, int chunk, int midpoint);
int		nb_topush_b(t_list *stack, int chunk, int midpoint);
void	chunk_add(t_list **stack, t_data *data, int chunk);
void	one_pb(t_data *data, int chunk, int midpt);
void	midpt_pb(t_data *data, int chunk);
void	all_to_b(t_data *data, int chunk);
void	midpt_pa(t_data *data, int chunk);
int		check_chunk(t_list *stack, int chunk);
void	setchunk_2node(t_list **stack, int nbr);
void	midpt2_pb(t_data *data, int chunk);
void	all2_to_b(t_data *data, int chunk);
void	midpt_alg(t_data *data);
void	big_sort(t_data *data);
void	one_pa(t_data *data, int chunk, int midpt);
int		check_one_chunk(t_list *stack);
void	midpt_pa_last(t_data *data, int chunk);
// void ft_printlist (t_list **stack);

#endif