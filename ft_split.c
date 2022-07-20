/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:17:06 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/06/22 10:15:55 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ft_split is used in case all the numbers in stack A come as a single
string in the arguments of the main. */

int	ft_wdcount(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_indexwd(char *s, char c, int index)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c && index >= 0)
		{
			ret = i;
			index--;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	if (index < 0)
		return (ret);
	return (-1);
}

static char	*ft_strdupwd(char *s, char c, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = start;
	len = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i++] != c)
			len++;
		word = malloc(sizeof(char) * (len + 1));
		if (!word)
			return (NULL);
		while (j < len)
			word[j++] = s[start++];
		word[j] = '\0';
		return (word);
	}
	return (NULL);
}

void	ft_freesplit(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		n;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_wdcount(s, c);
	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (NULL);
	while (i < n)
	{
		strs[i] = ft_strdupwd(s, c, ft_indexwd(s, c, i));
		if (!strs[i])
		{
			ft_freesplit(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
