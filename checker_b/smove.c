/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:02:50 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 11:39:18 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

/*
#include <stdio.h>
int	main(void)
{
	t_list	*stack;
	int tab[] = {5};
	int size = 1;
	int	i = 0;

	while (i < size)
		printf("%d ", tab[i++]);
	printf("\n");
	stack = init_list(tab, &size);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	stack = init_list(tab, &size);
	sa(&stack);
	while (stack)
	{
		printf("%d %d\n", (stack)->value, (stack)->index);
		(stack) = (stack)->next;
	}
	printf("\n");
	return (0);
}
*/