/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:55:10 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 15:59:49 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_of_two(t_stack **stk_a)
{
	if (!stk_a || !*stk_a)
		return ;
	if ((*stk_a)->id == 1)
		sa(stk_a);
}

static void	sort_of_tree(t_stack **stk_a, int size)
{
	if (!stk_a || !*stk_a)
		return ;
	if (find(*stk_a, size - 1) == 1)
		ra(stk_a);
	else if (find(*stk_a, size - 1) == 2)
		rra(stk_a);
	if (find(*stk_a, size - 2) == 1)
		sa(stk_a);
}

static void	sort_of_fore(t_stack **stk_a, t_stack **stk_b, int size)
{
	if (find(*stk_a, size - 4) == 4)
		rra(stk_a);
	else
		while ((*stk_a)->id != size - 4)
			ra(stk_a);
	pb(stk_a, stk_b);
	sort_of_tree(stk_a, size);
	pa(stk_a, stk_b);
}

static void	sort_of_five(t_stack **stk_a, t_stack **stk_b, int size)
{
	if (find(*stk_a, 0) > 3)
		while ((*stk_a)->id != 0)
			rra(stk_a);
	else
		while ((*stk_a)->id != 0)
			ra(stk_a);
	pb(stk_a, stk_b);
	sort_of_fore(stk_a, stk_b, size);
	pa(stk_a, stk_b);
}

void	sort(t_stack **stk_a, t_stack **stk_b)
{
	int	size;

	size = stksize(*stk_a);
	if (size == 2)
		sort_of_two(stk_a);
	else if (size == 3)
		sort_of_tree(stk_a, size);
	else if (size == 4)
		sort_of_fore(stk_a, stk_b, size);
	else if (size == 5)
		sort_of_five(stk_a, stk_b, size);
	else
	{
		if (size > 200)
			push_chunk(stk_a, stk_b, size, 9);
		else if (size > 5)
			push_chunk(stk_a, stk_b, size, 5);
		pushback(stk_a, stk_b, size);
	}
	lstclear(stk_a);
}
