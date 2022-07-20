/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrmove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:54:43 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 11:40:06 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*stack;
	int tab[] = {4, 5};
	int size = 2;
	int	i = 0;

	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
	stack = init_list(tab, &size);
	//printf("%p %p\n", stack->previous, stack->next);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	stack = init_list(tab, &size);
	rra(&stack);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	return (0);
}
*/