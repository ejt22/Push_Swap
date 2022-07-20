/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint1_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:11:38 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:32:10 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function calculates the size of a chunk. */

int	size_chunk(t_list *stack, int chunk)
{
	int		size;
	t_list	*current;

	size = 0;
	if (!stack)
		return (0);
	current = stack;
	while (current && current->chunk == chunk)
	{
		size++;
		current = current->next;
	}
	return (size);
}

/* This function calculates the midpoint of a chunk. */

int	midpoint_chunk(t_list *stack, int chunk)
{
	int		total;
	int		size;
	t_list	*current;

	if (!stack)
		return (0);
	size = size_chunk(stack, chunk);
	current = stack;
	total = 0;
	while (current && current->chunk == chunk)
	{
		total += current->value;
		current = current->next;
	}
	if (size % 2 == 0)
		return (1 + total / size);
	else
		return (total / size);
}

/* This function calculates the numbers of nodes to push from stack A. */

int	nb_topush_a(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;
	int		nbr;

	current = stack;
	nbr = 0;
	while (current && current->chunk == chunk)
	{
		if (current->value < midpoint)
			nbr++;
		current = current->next;
	}
	return (nbr);
}

/* This function calculates the numbers of nodes to push from stack B. */

int	nb_topush_b(t_list *stack, int chunk, int midpoint)
{
	t_list	*current;
	int		nbr;

	current = stack;
	nbr = 0;
	while (current && current->chunk == chunk)
	{
		if (current->value >= midpoint)
			nbr++;
		current = current->next;
	}
	return (nbr);
}

/* This function sets the chunk number of each element of the stack to
	the iter number. */

void	chunk_add(t_list **stack, t_data *data, int chunk)
{
	t_list	*current;

	current = *stack;
	while (current && current->chunk == chunk)
	{
		current->chunk = data->iter;
		current = current->next;
	}
}
