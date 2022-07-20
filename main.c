/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:28:50 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:34:01 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function initialises all the data. */

t_data	init_data(int *tab, int *size)
{
	int		*final_tab;
	t_data	data;

	final_tab = ft_sorted_index(tab, size);
	data.stack_a = init_list(final_tab, size);
	data.stack_b = NULL;
	data.size_a = ft_stack_size(data.stack_a);
	data.size_b = 0;
	data.iter = 0;
	return (data);
}

/* This function manages the cases that will cause to leave the program. */

int	leave_main(int *tab, int *size, int *error)
{
	if (*error == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (*error == -1)
		return (1);
	if (check_sorted(tab, size))
	{
		free(tab);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		error;
	int		size;
	int		*tab;
	t_data	data;

	error = 0;
	size = 0;
	tab = int_input(argc, argv, &size, &error);
	if (leave_main(tab, &size, &error))
		return (0);
	data = init_data(tab, &size);
	if (argc >= 3 && argc <= 6)
		medium_sort(&data.stack_a, &data.stack_b, &data);
	else if (argc > 6)
		big_sort(&data);
	ft_freelist(&data.stack_a);
	return (0);
}
