/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:56:56 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:32:42 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if a chunk at the top of a stack is sorted. */

int	check_chunk(t_list *stack, int chunk)
{
	t_list	*current;
	int		size;

	size = size_chunk(stack, chunk) - 1;
	current = stack;
	if (size == 0)
		return (1);
	else if (size == 1)
	{
		if (current->value < current->next->value)
			return (1);
		else
			return (0);
	}
	else
	{
		while (size--)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
		return (1);
	}
}

/* This function sets the chunk number of the top of a stack. */

void	setchunk_2node(t_list **stack, int nbr)
{
	(*stack)->chunk = nbr;
}

/* Given a midpoint and a number of nodes to push, this function pushes 
to stack B all the numbers under the midpoint. */

static void	move_2b(t_data *data, int midpoint, int nbr)
{
	int	count;

	count = 0;
	while (nbr)
	{
		if (data->stack_a->value >= midpoint)
		{
			ra(&data->stack_a);
			count++;
		}
		else
		{
			pb(&data->stack_a, &data->stack_b, data);
			setchunk_2node(&data->stack_b, data->iter);
			nbr--;
		}
	}
	while (count--)
		rra(&data->stack_a);
}

/* This function pushes to stack B all the numbers under midpoint of 
the chunk. */

void	midpt2_pb(t_data *data, int chunk)
{
	int	midpoint;
	int	nbr;

	midpoint = midpoint_chunk(data->stack_a, chunk);
	nbr = nb_topush_a(data->stack_a, chunk, midpoint);
	data->iter++;
	if (!check_chunk(data->stack_a, chunk))
		move_2b(data, midpoint, nbr);
	else
		return ;
}

/* This function uses the midpoint algorithm until all but 2 nodes of chunk
are pushed to stack B. */

void	all2_to_b(t_data *data, int chunk)
{
	int	size;

	size = size_chunk(data->stack_a, chunk);
	while (size > 2)
	{
		if (check_chunk(data->stack_a, chunk))
			return ;
		midpt2_pb(data, chunk);
		size = size_chunk(data->stack_a, chunk);
	}
	if (size == 2 && data->stack_a->value > data->stack_a->next->value)
		sa(&data->stack_a);
}
