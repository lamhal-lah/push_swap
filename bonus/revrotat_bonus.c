/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotat_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:59:29 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 17:34:08 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	revrotat(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	tmp1 = tmp -> next;
	while (tmp1 -> next)
	{
		tmp1 = tmp1 -> next;
		tmp = tmp -> next;
	}
	tmp -> next = NULL;
	addfront (list, tmp1);
}

void	rra(t_stack **stk_a)
{
	revrotat(stk_a);
}

void	rrb(t_stack **stk_b)
{
	revrotat(stk_b);
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	revrotat(stk_a);
	revrotat(stk_b);
}
