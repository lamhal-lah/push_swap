/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:56:39 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 16:14:44 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_stack *stk, int id)
{
	t_stack	*tmp;
	int		i;

	if (!stk)
		return (0);
	i = 1;
	tmp = stk;
	while (tmp)
	{
		if (tmp->id == id)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	bestmove(t_stack **b, int size)
{
	int	pos_max;
	int	pos_second_max;
	int	move_max;
	int	move_s_max;

	pos_max = find(*b, size - 1);
	pos_second_max = find(*b, size -2);
	move_max = pos_max;
	move_s_max = pos_second_max;
	if (pos_max > size / 2 + 1)
		move_max = size - pos_max + 2;
	if (pos_second_max > size / 2 + 1)
		move_s_max = size - pos_second_max + 2;
	if (move_max <= move_s_max && pos_max > size / 2 + 1)
		while ((*b)->id != size - 1)
			rrb(b);
	else if (move_max <= move_s_max && pos_max <= size / 2 + 1)
		while ((*b)->id != size - 1)
			rb(b);
	else if (move_max > move_s_max && pos_second_max > size / 2 + 1)
		while ((*b)->id != size - 2)
			rrb(b);
	else if (move_max > move_s_max && pos_second_max <= size / 2 + 1)
		while ((*b)->id != size - 2)
			rb(b);
}

void	pushback(t_stack **stk_a, t_stack **stk_b, int size)
{
	while (*stk_b)
	{
		if (!(*stk_b)->next)
		{
			pa(stk_a, stk_b);
			break ;
		}
		bestmove(stk_b, size);
		if ((*stk_b)->id == size - 2)
		{
			pa(stk_a, stk_b);
			if (find(*stk_b, size - 1) > (size - 1) / 2 + 1)
				while ((*stk_b)->id != size - 1)
					rrb(stk_b);
			else
				while ((*stk_b)->id != size - 1)
					rb(stk_b);
			pa(stk_a, stk_b);
			sa(stk_a);
			size--;
		}
		else
			pa(stk_a, stk_b);
		size--;
	}
}
