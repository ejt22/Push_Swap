/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_last1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:48:49 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 13:16:17 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function finds the first value above midpoint in chunk B from
the top of the chunk. */

static int	first_top_b(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current && current->chunk == chunk
		&& current->value < midpoint)
		current = current->next;
	if (current->value > midpoint)
		return (current->index);
	else
		return (-1);
}
/* This function finds first value above midpoint in chunk B from
the bottom of the chunk. */

static int	first_bottom_b(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;

	if (!stack)
		return (0);
	current = ft_gotolast(&stack);
	while (current && current->chunk == chunk
		&& current->value < midpoint)
		current = current->previous;
	if (current->value > midpoint)
		return (current->index);
	else
		return (-1);
}

/* This function takes a node, rotates the stack until it reaches the top
and moves it to stack A. */

static void	m_top_b(t_data *data, int top)
{
	while (top)
	{
		rb(&data->stack_b);
		top--;
	}
	pa(&data->stack_a, &data->stack_b, data);
}

/* This function takes a node, reversely rotates the stack until it reaches 
the top and moves it to stack A. */

static void	m_bottom_b(t_data *data, int b, int chunk)
{
	int	size;

	size = size_chunk(data->stack_b, chunk);
	while (b < size)
	{
		rrb(&data->stack_b);
		b++;
	}
	pa(&data->stack_a, &data->stack_b, data);
}

/* This function moves the node from stack B with value above midpoint closest 
to top or to bottom into stack A, choosing the one with least moves. */

void	one_pa(t_data *data, int chunk, int midpt)
{
	int	top;
	int	bottom;
	int	size;

	top = first_top_b(data->stack_b, chunk, midpt);
	bottom = first_bottom_b(data->stack_b, chunk, midpt);
	size = size_chunk(data->stack_b, chunk);
	if (top >= 0 && bottom >= 0 && top <= (size - bottom - 1))
		m_top_b(data, top);
	else if (top >= 0 && bottom >= 0 && top > (size - bottom - 1))
		m_bottom_b(data, bottom, chunk);
	else if (top >= 0 && bottom < 0)
		m_top_b(data, top);
	else if (top < 0 && bottom >= 0)
		m_bottom_b(data, bottom, chunk);
	else
		return ;
}
