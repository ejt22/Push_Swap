/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:52:04 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/06 15:23:05 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

/* These functions replace the array of values by their index in the sorted
array. Sorting these indices is equivalent to sorting the initial values. */

static int	*ft_copy_tab(int *tab, int *size)
{
	int	i;
	int	*copy_tab;

	if (!tab || !size)
		return (NULL);
	copy_tab = malloc(sizeof(int) * (*size));
	if (!copy_tab)
		return (NULL);
	i = 0;
	while (i < *size)
	{
		copy_tab[i] = tab[i];
		i++;
	}
	return (copy_tab);
}

static int	*ft_sorted_tab(int *tab, int *size)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted_tab;

	sorted_tab = ft_copy_tab(tab, size);
	i = 0;
	while (i < *size - 1)
	{
		j = i + 1;
		while (j < *size)
		{
			if (sorted_tab[j] < sorted_tab[i])
			{
				tmp = sorted_tab[i];
				sorted_tab[i] = sorted_tab[j];
				sorted_tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted_tab);
}

int	*ft_sorted_index(int *tab, int *size)
{
	int	i;
	int	j;
	int	*sorted_tab;
	int	*final_tab;

	sorted_tab = ft_sorted_tab(tab, size);
	final_tab = malloc(sizeof(int) * (*size));
	if (final_tab)
	{
		i = 0;
		while (i < (*size))
		{
			j = 0;
			while (j < *size)
			{
				if (sorted_tab[j] == tab[i])
					final_tab[i] = j;
				j++;
			}
			i++;
		}
	}
	free(sorted_tab);
	free(tab);
	return (final_tab);
}

/*
#include <stdio.h>

int	main(void)
{
	// int tab[10] = {44, 55, 12, 90, 89, 27, 453, 1785, 61, 8};
	int	*final_tab;
	int tab[10] = {-4, -5, -1, -9, -8, -2, -3, -7, -6, 0};
	int size = 10;
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	final_tab = ft_sorted_index(tab, &size);
	i = 0;
	while (i < size)
	{
		printf("%d ", final_tab[i]);
		i++;
	}
	return (0);
}
*/