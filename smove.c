/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:02:50 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:27:20 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions execute the swap operations on the stacks. */

void	sa(t_list **stack)
{
	t_list	*second;
	int		tmp;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	second = (*stack)->next;
	tmp = (*stack)->value;
	(*stack)->value = second->value;
	second->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	t_list	*second;
	int		tmp;

	if (!((*stack)->previous) && !((*stack)->next))
		return ;
	second = (*stack)->next;
	tmp = (*stack)->value;
	(*stack)->value = second->value;
	second->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
