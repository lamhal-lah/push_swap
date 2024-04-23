/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:57:43 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 17:32:38 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	push(stk_b, stk_a);
}

void	pb(t_stack **stk_a, t_stack **stk_b)
{
	push(stk_a, stk_b);
}
