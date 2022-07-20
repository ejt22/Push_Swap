/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:42:10 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:25:42 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions execute the rotation operations on the stacks. */

void	ra(t_list **stack)
{
	t_list	*last;
	t_list	*second;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	last = ft_gotolast(stack);
	second = (*stack)->next;
	last->next = (*stack);
	(*stack)->previous = last;
	(*stack)->next = NULL;
	second->previous = NULL;
	(*stack) = second;
	re_index(stack);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	t_list	*last;
	t_list	*second;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	last = ft_gotolast(stack);
	second = (*stack)->next;
	last->next = (*stack);
	(*stack)->previous = last;
	(*stack)->next = NULL;
	second->previous = NULL;
	(*stack) = second;
	re_index(stack);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
