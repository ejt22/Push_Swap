/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:55:33 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:23:20 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function pushes the last two nodes in stack B into stack A. */

static void	two_inchunk_b(t_data *data)
{
	t_list	*current;

	current = data->stack_b;
	if (current->value < current->next->value)
		sb(&data->stack_b);
	pa(&data->stack_a, &data->stack_b, data);
	pa(&data->stack_a, &data->stack_b, data);
}

/* This function pushes all the nodes above the midpoint in a chunk from stack B
into stack A except for the case where it is the last chunk in stack B. */

static void	big_middle_chunk_b(t_data *data, int chunk)
{
	int	midpoint;
	int	nbr;
	int	count;

	midpoint = midpoint_chunk(data->stack_b, chunk);
	nbr = nb_topush_b(data->stack_b, chunk, midpoint);
	count = 0;
	while (nbr)
	{
		if (data->stack_b->value < midpoint)
		{
			rb(&data->stack_b);
			count++;
		}
		else
		{
			pa(&data->stack_a, &data->stack_b, data);
			nbr--;
		}
	}
	while (count--)
		rrb(&data->stack_b);
}

/* This function pushes to stack A all the nodes of a chunk of stack B
which has 3 or more nodes in it. */

static void	big_chunk_b(t_data *data, int chunk)
{
	if (check_one_chunk(data->stack_b))
		midpt_pa_last(data, chunk);
	else
		big_middle_chunk_b(data, chunk);
}

/* This function pushes to stack A all the nodes of a chunk of stack B. */

void	midpt_pa(t_data *data, int chunk)
{
	int	size;

	size = size_chunk(data->stack_b, chunk);
	if (size == 1)
		pa(&data->stack_a, &data->stack_b, data);
	else if (size == 2)
		two_inchunk_b(data);
	else
		big_chunk_b(data, chunk);
}
