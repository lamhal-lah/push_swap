/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:11:36 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/27 20:22:14 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

int	stksize(t_stack *stk)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stk;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	indexer(t_stack *stk, t_stack *node)
{
	t_stack		*tmp;
	static int	i;
	int			j;

	j = 0;
	if (!node)
		return ;
	if (!stk)
	{
		node->id = i;
		return ;
	}
	tmp = stk;
	while (tmp)
	{
		if (node->nbr < tmp->nbr)
		{
			tmp->id = tmp->id + 1;
			j++;
		}
		tmp = tmp->next;
	}
	i++;
	node->id = i - j;
}

void	push_chunk(t_stack **stk_a, t_stack **stk_b, int size, int div)
{
	int	chunk;
	int	mdchunk;
	int	i;

	chunk = 0;
	mdchunk = size / (div * 2);
	while (*stk_a)
	{
		chunk += size / div;
		i = 0;
		while ((*stk_a) && i++ < size / div)
		{
			while ((*stk_a)->id >= chunk)
				ra(stk_a);
			pb(stk_a, stk_b);
			if ((*stk_b)->id >= mdchunk && (*stk_b)->next && i < size / div
				&& (*stk_a) && (*stk_a)->id >= chunk)
				rr(stk_a, stk_b);
			else if ((*stk_b)->next && (*stk_b)->id >= mdchunk)
				rb(stk_b);
		}
		mdchunk += size / div;
	}
}

int	issorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
