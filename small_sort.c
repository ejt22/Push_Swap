/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:29:13 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:27:07 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function sorts stack A with two nodes. */

void	sort_two(t_list **stack)
{
	t_list	*next;

	next = (*stack)->next;
	if ((*stack)->value > next->value)
		sa(stack);
}

static void	case_1(t_list **stack)
{
	sa(stack);
	ra(stack);
}

static void	case_2(t_list **stack)
{
	sa(stack);
	rra(stack);
}

/* This function sorts stack A with three nodes. */

void	sort_three(t_list **stack)
{
	t_list	*second;
	t_list	*third;

	second = (*stack)->next;
	third = second->next;
	if ((*stack)->value < second->value && (*stack)->value < third->value
		&& third->value < second->value)
		case_1(stack);
	if (third->value < second->value && third->value < (*stack)->value
		&& second->value < (*stack)->value)
		case_2(stack);
	if (second->value < (*stack)->value && second->value < third->value
		&& (*stack)->value < third->value)
		sa(stack);
	if (second->value < (*stack)->value && second->value < third->value
		&& third->value < (*stack)->value)
		ra(stack);
	if (third->value < second->value && third->value < (*stack)->value
		&& (*stack)->value < second->value)
		rra(stack);
}
