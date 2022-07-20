/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:08:16 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/06 15:20:38 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* This function checks for white spaces. */

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

/* This function outputs an error for variables outside of int range. */

static int	prot_atoi(unsigned long long res, int sign, int size, int *error)
{
	if ((((res > INT_MAX) || size > 19) && sign > 0))
	{
		*error = 1;
		return (-1);
	}
	else if ((((res > 2147483648) || size > 19)) && (sign < 0))
	{
		*error = 1;
		return (0);
	}
	return (res * sign);
}

/* This function is used in the parsing in order to take out the int part of
a string. */

int	ft_atoi(char *str, int *error)
{
	int					i;
	int					sign;
	int					size;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	size = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (str[i] < '0' || str[i] > '9')
		*error = 1;
	while (str[i] >= '0' && str[i] <= '9' && ++size)
		res = res * 10 + (str[i++] - '0');
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0')
		*error = 1;
	return (prot_atoi(res, sign, size, error));
}
/*
int	main(void)
{
	char str[] = "-2147483649";
	int		error = 0;

	printf("%d\n", ft_atoi(str, &error));
	printf("%d\n", error);
	return (0);
}
*/