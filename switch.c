/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:07:54 by lamhal            #+#    #+#             */
/*   Updated: 2024/04/19 17:29:22 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	switcch(t_stack **list)
{
	t_stack	*tmp;
	int		swap;

	tmp = *list;
	if (!list || !*list || !(*list)->next)
		return ;
	swap = tmp->nbr;
	tmp->nbr = tmp->next->nbr;
	tmp->next->nbr = swap;
	swap = tmp->id;
	tmp->id = tmp->next->id;
	tmp->next->id = swap;
}

void	sa(t_stack **stk_a)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	switcch(stk_a);
	ft_putchar("sa\n");
}

void	sb(t_stack **stk_b)
{
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	switcch(stk_b);
	ft_putchar("sb\n");
}

void	ss(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !*stk_a || !(*stk_a)->next)
		return ;
	if (!stk_b || !*stk_b || !(*stk_b)->next)
		return ;
	switcch(stk_a);
	switcch(stk_b);
	ft_putchar("ss\n");
}
