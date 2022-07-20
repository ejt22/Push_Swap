/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:17:01 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/08 12:45:31 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

/* This function takes the arguments of the main as arguments and outputs a 
string of strings. */

static char	**ft_str_input(int argc, char **argv, int *size, int *error)
{
	char	**str_input;

	str_input = NULL;
	if (argc == 1)
		*error = -1;
	else if (argc == 2)
	{
		str_input = ft_split(argv[1], ' ');
		*size = ft_wdcount(argv[1], ' ');
	}	
	else if (argc > 2)
	{
		str_input = &argv[1];
		*size = argc - 1;
	}
	else
		*error = 1;
	return (str_input);
}

/* This function takes an array of int and checks for duplicates */

static int	check_duplicates(int *tab, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < *size -1)
	{
		j = i + 1;
		while (j < *size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* This function takes an array of int and checks whether they are sorted */

int	check_sorted(int *tab, int *size)
{
	int	i;

	i = 0;
	while (i < (*size -1))
	{
		if (tab[i + 1] <= tab[i])
			return (0);
		i++;
	}
	return (1);
}

/* This function takes the arguments of the main and outputs an array of 
int and also checks for duplicates. */

int	*int_input(int argc, char **argv, int *size, int *error)
{
	char	**str_input;
	int		*tab;
	int		i;

	str_input = ft_str_input(argc, argv, size, error);
	tab = malloc(sizeof(int) * (*size));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		tab[i] = ft_atoi(str_input[i], error);
		i++;
	}
	if (check_duplicates(tab, size))
		*error = 1;
	if (argc == 2)
		ft_freesplit(str_input);
	return (tab);
}

// int	main(void)
// {
// 	int	tab[6] = {2, 1, 3, 4, 45};
// 	int	size;

// 	size = 5;
// 	printf("%d\n", check_sorted(tab, &size));
// 	return (0);
// }