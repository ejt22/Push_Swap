/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint1b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:02:30 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:32:30 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function pushes all the nodes in chunk with values below midpoint
into stack B. */

void	midpt_pb(t_data *data, int chunk)
{
	int	midpoint;
	int	nbr;

	midpoint = midpoint_chunk(data->stack_a, chunk);
	nbr = nb_topush_a(data->stack_a, chunk, midpoint);
	while (nbr)
	{
		one_pb(data, chunk, midpoint);
		nbr--;
	}
	data->iter++;
	chunk_add(&data->stack_b, data, chunk);
}

/* This function uses the midpoint to move all of stack A into stack B */

void	all_to_b(t_data *data, int chunk)
{
	int	size;

	size = ft_stack_size(data->stack_a);
	while (size > 3)
	{
		midpt_pb(data, chunk);
		size = ft_stack_size(data->stack_a);
	}
	if (size == 2)
		sort_two(&data->stack_a);
	if (size == 3)
		sort_three(&data->stack_a);
}
