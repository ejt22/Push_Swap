/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_last2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:48:33 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:34:27 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if there is only one chunk remaining in the stack. */

int	check_one_chunk(t_list *stack)
{
	t_list	*current;
	int		chunk;

	current = stack;
	chunk = stack->chunk;
	while (current)
	{
		if (current->chunk != chunk)
			return (0);
		current = current->next;
	}
	return (1);
}

/* This function pushes all the nodes in chunk with values strictly above
midpoint into stack A. */

void	midpt_pa_last(t_data *data, int chunk)
{
	int	midpoint;
	int	nbr;

	midpoint = midpoint_chunk(data->stack_b, chunk);
	nbr = nb_topush_b(data->stack_b, chunk, midpoint) - 1;
	while (nbr)
	{
		one_pa(data, chunk, midpoint);
		nbr--;
	}
}
