/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrmove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:54:43 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:25:54 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions execute the reverse rotation operations on the stacks. */

void	rra(t_list **stack)
{
	t_list	*last;
	t_list	*bflast;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	last = ft_gotolast(stack);
	bflast = last->previous;
	(*stack)->previous = last;
	last->previous = NULL;
	last->next = (*stack);
	bflast->next = NULL;
	(*stack) = last;
	re_index(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	t_list	*last;
	t_list	*bflast;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	last = ft_gotolast(stack);
	bflast = last->previous;
	(*stack)->previous = last;
	last->previous = NULL;
	last->next = (*stack);
	bflast->next = NULL;
	(*stack) = last;
	re_index(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
