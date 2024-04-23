/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:52:08 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 15:50:45 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	rotat(stk_a);
	ft_putchar("ra\n");
}

void	rb(t_stack **stk_b)
{
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	rotat(stk_b);
	ft_putchar("rb\n");
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	rotat(stk_a);
	rotat(stk_b);
	ft_putchar("rr\n");
}
