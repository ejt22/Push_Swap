/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:27:24 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:31:05 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function checks if stack A is sorted. */

int	check_a(t_data *data)
{
	t_list	*current;
	int		size;

	current = data->stack_a;
	size = data->size_a - 1;
	while (size--)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/* This function starts with the top of stack B, moves the top chunk into A
using midpoint and sends back all the numbers that 
are not sorted yet to stack B using midpoint. */

void	midpt_alg(t_data *data)
{
	int	chunk;

	while (data->size_b)
	{
		chunk = data->stack_b->chunk;
		midpt_pa(data, chunk);
		chunk = data->stack_a->chunk;
		if (check_a(data) == 0)
			all2_to_b(data, chunk);
	}
}

/* This function sorts stack A for 6 or more numbers in stack A. */

void	big_sort(t_data *data)
{
	int	chunk;

	chunk = 0;
	all_to_b(data, chunk);
	midpt_alg(data);
}
