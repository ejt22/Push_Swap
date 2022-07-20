/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:42:10 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 11:39:43 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*stack;
	int tab[] = {4, 9};
	int size = 2;
	int	i = 0;

	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
	stack = init_list(tab, &size);
	printf("%p %p\n", stack->previous, stack->next);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	stack = init_list(tab, &size);
	rb(&stack);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	return (0);
}
*/