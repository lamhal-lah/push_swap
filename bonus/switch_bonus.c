/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:12:05 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 17:37:13 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	switcch(t_stack **list)
{
	t_stack	*tmp;
	void	*swap;

	tmp = *list;
	if (!list || !*list || !(*list)->next)
		return ;
	swap = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = swap;
}

void	sa(t_stack **stk_a)
{
	switcch(stk_a);
}

void	sb(t_stack **stk_b)
{
	switcch(stk_b);
}

void	ss(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	switcch(stk_a);
	switcch(stk_b);
}
