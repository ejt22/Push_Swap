/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmove_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:12:55 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/05 13:15:22 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions execute the push operations on stack A. */

static void	pa_empty_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_b;
	t_list	*second_b;

	first_b = (*stack_b);
	second_b = first_b->next;
	second_b->previous = NULL;
	first_b->next = NULL;
	(*stack_b) = second_b;
	(*stack_a) = first_b;
	re_index(stack_b);
}

static void	pa_last_b(t_list **stack_a, t_list **stack_b)
{
	(*stack_a)->previous = (*stack_b);
	(*stack_b)->next = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = NULL;
	re_index(stack_a);
}

void	pa(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*first_b;
	t_list	*second_b;

	if (!stack_b || !(*stack_b))
		return ;
	if (!stack_a || !(*stack_a))
		pa_empty_a(stack_a, stack_b);
	else if (!((*stack_b)->previous) && !((*stack_b)->next))
		pa_last_b(stack_a, stack_b);
	else
	{
		first_b = (*stack_b);
		second_b = first_b->next;
		second_b->previous = NULL;
		first_b->next = (*stack_a);
		(*stack_a)->previous = first_b;
		(*stack_b) = second_b;
		(*stack_a) = first_b;
		re_index(stack_b);
		re_index(stack_a);
	}
	data->size_a += 1;
	data->size_b -= 1;
	write(1, "pa\n", 3);
}
