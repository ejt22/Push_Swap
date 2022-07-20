/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:28:50 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/20 14:55:40 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	error_mgt(int *error)
{
	if (*error == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	execute(t_data *data, int *error)
{
	char	*line;

	line = get_next_line(0, error);
	while (line)
	{
		execute_cmd(line, data, error);
		if (error_mgt(error))
			return (1);
		free(line);
		line = get_next_line(0, error);
	}
	if (line == NULL)
		final_check(data);
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
	if (execute(&data, &error))
		return (0);
	if (data.size_a)
		ft_freelist(&data.stack_a);
	if (data.size_b)
		ft_freelist(&data.stack_b);
	return (0);
}
