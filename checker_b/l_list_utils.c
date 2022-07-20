/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:23:03 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:55:19 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* This function re-indexes a stack after some changes have occurred. */

void	re_index(t_list **stack)
{
	int		index;
	t_list	*current;

	index = 0;
	current = (*stack);
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

/* This function outputs a pointer to the last node of a stack. */

t_list	*ft_gotolast(t_list **stack)
{
	t_list	*last;

	if (!stack)
		return (NULL);
	last = (*stack);
	while (last->next)
		last = last->next;
	return (last);
}

/* This function outputs the number of nodes in a stack. */

int	ft_stack_size(t_list *stack)
{
	int		size;
	t_list	*current;

	if (!stack)
		return (0);
	size = 0;
	current = stack;
	while (current->next)
	{
		size++;
		current = current->next;
	}
	return (size + 1);
}

static void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

/* This function frees the linked list. */

void	ft_freelist(t_list **lst)
{
	t_list	*ptr;

	while (lst && (*lst))
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst);
		(*lst) = ptr;
	}
}
