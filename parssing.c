/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:04:21 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/24 15:12:46 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_exit(t_stack **stk_a, char **str)
{
	int	i;

	if (!stk_a && !str)
		exit (1);
	if (!str)
	{
		lstclear(stk_a);
		exit (1);
	}
	if (*stk_a)
		lstclear(stk_a);
	if (str)
	{
		i = 0;
		while (str[i])
			free(str[i++]);
		free(str);
	}
	write (2, "Error\n", 6);
	exit (1);
}

static int	ft_atoi(char *str)
{
	long	nbr;
	int		sgn;

	nbr = 0;
	sgn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		nbr = nbr * 10 + *str - 48;
		str++;
		if ((nbr > 2147483647 && sgn == 1) || (nbr > 2147483648 && sgn == -1))
			return (0);
	}
	return (nbr * sgn);
}

static void	check_parssing(t_stack **stk_a, char **str, int nbr, int pos)
{
	if (nbr == 0 && ((str[pos][0] != '0' || str[pos][1] != 0) &&
	(str[pos][0] != '-' || str[pos][1] != '0' || str[pos][2] != 0) &&
	(str[pos][0] != '+' || str[pos][1] != '0' || str[pos][2] != 0)))
		free_exit(stk_a, str);
	if (isinlst(*stk_a, nbr))
		free_exit(stk_a, str);
}

static void	fill_stack(char **str, t_stack **stk_a)
{
	int		nbr;
	int		i;
	t_stack	*new;

	i = 0;
	while (str[i])
	{
		nbr = ft_atoi(str[i]);
		check_parssing(stk_a, str, nbr, i);
		new = lstnew(nbr);
		if (!new)
		{
			lstclear(stk_a);
			while (str[i])
				i++;
			ft_free(str, i);
			exit (1);
		}
		indexer(*stk_a, new);
		addback(stk_a, new);
		i++;
	}
	ft_free(str, i);
}

void	ft_fillstack(t_stack **stk_a, char **av)
{
	char	**str;
	int		i;

	i = 1;
	while (av[i])
	{
		str = ft_split(av[i], ' ');
		if (!str || !*str)
			free_exit(stk_a, str);
		fill_stack(str, stk_a);
		i++;
	}
}
