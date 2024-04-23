/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:35:18 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 16:12:42 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **list, t_stack **lst)
{
	t_stack	*tmp;

	if (!list || !lst || !*list)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp -> next = NULL;
	addfront(lst, tmp);
}

void	pa(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !stk_b || !*stk_b)
		return ;
	push(stk_b, stk_a);
	ft_putchar("pa\n");
}

void	pb(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !stk_b || !*stk_a)
		return ;
	push(stk_a, stk_b);
	ft_putchar("pb\n");
}
