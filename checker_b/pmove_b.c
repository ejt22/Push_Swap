/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmove_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:20:18 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 11:40:21 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* These functions execute the push operations on stack B. */

static void	pb_empty_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*second_a;

	first_a = (*stack_a);
	second_a = first_a->next;
	second_a->previous = NULL;
	first_a->next = NULL;
	(*stack_a) = second_a;
	(*stack_b) = first_a;
	re_index(stack_a);
}

static void	pb_last_a(t_list **stack_a, t_list **stack_b)
{
	(*stack_b)->previous = (*stack_a);
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = NULL;
	re_index(stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b, t_data *data)
{
	t_list	*first_a;
	t_list	*second_a;

	if (!stack_a || !(*stack_a))
		return ;
	if (!stack_b || !(*stack_b))
		pb_empty_b(stack_a, stack_b);
	else if (!((*stack_a)->previous) && !((*stack_a)->next))
		pb_last_a(stack_a, stack_b);
	else
	{
		first_a = (*stack_a);
		second_a = first_a->next;
		second_a->previous = NULL;
		first_a->next = (*stack_b);
		(*stack_b)->previous = first_a;
		(*stack_a) = second_a;
		(*stack_b) = first_a;
		re_index(stack_a);
		re_index(stack_b);
	}
	data->size_a -= 1;
	data->size_b += 1;
}
