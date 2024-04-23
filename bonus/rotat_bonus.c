/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:01:58 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 17:35:26 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotat(t_stack **list)
{
	t_stack	*tmp;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp -> next = NULL;
	addback(list, tmp);
}

void	ra(t_stack **stk_a)
{
	rotat(stk_a);
}

void	rb(t_stack **stk_b)
{
	rotat(stk_b);
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	rotat(stk_a);
	rotat(stk_b);
}
