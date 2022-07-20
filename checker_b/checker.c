/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:19:58 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 13:08:57 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

		i = 0;
	if (n > 0)
	{
		while ((s1[i] || s2[i]) && (s1[i] == s2[i]) && i < n - 1)
			i++;
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
	return (0);
}

void	execute_cmd(char *s, t_data *data, int *error)
{
	if (s && !ft_strncmp(s, "sa\n", 3))
		sa(&data->stack_a);
	else if (s && !ft_strncmp(s, "sb\n", 3))
		sb(&data->stack_b);
	else if (s && !ft_strncmp(s, "ss\n", 3))
		ss(&data->stack_a, &data->stack_b);
	else if (s && !ft_strncmp(s, "ra\n", 3))
		ra(&data->stack_a);
	else if (s && !ft_strncmp(s, "rb\n", 3))
		rb(&data->stack_b);
	else if (s && !ft_strncmp(s, "rr\n", 3))
		rr(&data->stack_a, &data->stack_b);
	else if (s && !ft_strncmp(s, "rra\n", 4))
		rra(&data->stack_a);
	else if (s && !ft_strncmp(s, "rrb\n", 4))
		rrb(&data->stack_b);
	else if (s && !ft_strncmp(s, "rrr\n", 4))
		rrr(&data->stack_a, &data->stack_b);
	else if (s && !ft_strncmp(s, "pa\n", 3))
		pa(&data->stack_a, &data->stack_b, data);
	else if (s && !ft_strncmp(s, "pb\n", 3))
		pb(&data->stack_a, &data->stack_b, data);
	else if (s)
		*error = 1;
}

int	check_sorted_a(t_data *data)
{
	t_list	*current;

	current = data->stack_a;
	while (data->size_a > 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		data->size_a--;
	}
	return (1);
}

void	final_check(t_data *data)
{
	if (check_sorted_a(data) && data->size_b == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
