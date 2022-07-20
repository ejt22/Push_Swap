/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:36:03 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:31:46 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function rotates or reverse rotates one stack so that nbr ends 
at the top of the stack. */

void	clever_rotate(t_list **stack, int nbr)
{
	t_list	*current;
	int		size;

	current = *stack;
	size = ft_stack_size(*stack);
	while (current->value != nbr)
		current = current->next;
	if (current->index <= (size / 2))
	{
		while ((*stack)->value != nbr)
			ra(stack);
	}
	else
	{
		while ((*stack)->value != nbr)
			rra(stack);
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b, t_data *data)
{
	clever_rotate(stack_a, 0);
	pb(stack_a, stack_b, data);
	sort_three(stack_a);
	clever_rotate(stack_a, 1);
	pa(stack_a, stack_b, data);
}

static void	sort_five(t_list **stack_a, t_list **stack_b, t_data *data)
{
	clever_rotate(stack_a, 0);
	pb(stack_a, stack_b, data);
	clever_rotate(stack_a, 1);
	pb(stack_a, stack_b, data);
	sort_three(stack_a);
	pa(stack_a, stack_b, data);
	pa(stack_a, stack_b, data);
}

void	medium_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b, data);
	else if (size == 5)
		sort_five(stack_a, stack_b, data);
}
