/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:27:50 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/24 16:05:07 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstnew(int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = val;
	node->next = NULL;
	return (node);
}

void	lstclear(t_stack **stk)
{
	t_stack	*tmp;

	if (!stk || !*stk)
		return ;
	tmp = *stk;
	while (*stk)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
	}
	*stk = NULL;
}

void	addback(t_stack **stk, t_stack *node)
{
	t_stack	*tmp;

	tmp = *stk;
	if (!tmp)
	{
		*stk = node;
		return ;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void	addfront(t_stack **stk, t_stack *node)
{
	if (!stk || !node)
		return ;
	node->next = *stk;
	*stk = node;
}

int	isinlst(t_stack *lst, int n)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->nbr == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
