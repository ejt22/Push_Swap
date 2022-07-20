/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint1a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:35:26 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:32:19 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function finds first value below midpoint in the chunk from
the top of the chunk. */

static int	first_top(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current && current->chunk == chunk
		&& current->value > midpoint)
		current = current->next;
	if (current->value < midpoint)
		return (current->index);
	else
		return (-1);
}

/* This function finds first value below midpoint in the chunk from
the bottom of the chunk. */

static int	first_bottom(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;

	if (!stack)
		return (0);
	current = ft_gotolast(&stack);
	while (current && current->chunk == chunk
		&& current->value > midpoint)
		current = current->previous;
	if (current->value < midpoint)
		return (current->index);
	else
		return (-1);
}

/* This function takes a node and rotates it until it reaches the top and moves 
it to stack B. */

static void	m_top(t_data *data, int top)
{
	while (top)
	{
		ra(&data->stack_a);
		top--;
	}
	pb(&data->stack_a, &data->stack_b, data);
}

/* This function takes a node and rotates reversely it until it reaches the top 
and moves it to stack B. */

static void	m_bottom(t_data *data, int b, int chunk)
{
	int	size;

	size = size_chunk(data->stack_a, chunk);
	while (b < size)
	{
		rra(&data->stack_a);
		b++;
	}
	pb(&data->stack_a, &data->stack_b, data);
}

/* This function moves the node from stack A with value below midpoint closest 
to top or to bottom into stack B, choosing the one with least moves. */

void	one_pb(t_data *data, int chunk, int midpt)
{
	int	top;
	int	bottom;
	int	size;

	top = first_top(data->stack_a, chunk, midpt);
	bottom = first_bottom(data->stack_a, chunk, midpt);
	size = size_chunk(data->stack_a, chunk);
	if (top >= 0 && bottom >= 0 && top <= (size - bottom - 1))
		m_top(data, top);
	else if (top >= 0 && bottom >= 0 && top > (size - bottom - 1))
		m_bottom(data, bottom, chunk);
	else if (top >= 0 && bottom < 0)
		m_top(data, top);
	else if (top < 0 && bottom >= 0)
		m_bottom(data, bottom, chunk);
	else
		return ;
}
