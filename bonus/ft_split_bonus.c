/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:56:16 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/13 22:32:41 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

void	ft_free(char **str, int l)
{
	while (l--)
		free(str[l]);
	free(str);
}

static char	*ft_word(char *str, char c, int *l)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	*l = i;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	int		i;
	int		l;
	int		cnt;

	i = 0;
	if (!s)
		return (NULL);
	cnt = count_words(s, c);
	strs = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (i < cnt)
	{
		while (*s == c)
			s++;
		strs[i] = ft_word(s, c, &l);
		if (strs[i] == NULL)
			return (ft_free(strs, i), NULL);
		i++;
		s += l;
	}
	strs[i] = NULL;
	return (strs);
}
