/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:10:01 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/21 17:31:16 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*lstnew(void *content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	lstclear(t_stack **stk)
{
	t_stack	*tmp;
	void	*data;

	if (!stk || !*stk)
		return ;
	tmp = *stk;
	while (*stk)
	{
		tmp = *stk;
		data = tmp->data;
		free(data);
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
