/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:06:01 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/25 12:53:21 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

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
void	re_index(t_list **stack);;
t_list	*init_list(int	*tab, int *size);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b, t_data *data);
void	pa(t_list **stack_a, t_list **stack_b, t_data *data);
int		leave_main(int *tab, int *size, int *error);
t_data	init_data(int *tab, int *size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		search_newline(char *s);
char	*read_and_stash(int fd, char *stash, int *error);
char	*extract_line(char *line_in);
char	*clean_up(char *line_in);
char	*get_next_line(int fd, int *error);
void	execute_cmd(char *s, t_data *data, int *error);
int		check_sorted_a(t_data *data);
void	final_check(t_data *data);
//void ft_printlist (t_list **stack);

#endif