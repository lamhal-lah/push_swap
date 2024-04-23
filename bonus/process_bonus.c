/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:21:01 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 22:48:16 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fill_list_instr(t_stack **inst, t_stack **stk_a)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_if_valid(line))
		{
			lstclear(stk_a);
			lstclear(inst);
			write(2, "Error\n", 6);
			exit(1);
		}
		addback(inst, lstnew(line));
		line = get_next_line(0);
	}
}

void	execut_instr(t_stack **stk_a, t_stack **stk_b, t_stack **inst)
{
	t_stack	*tmp;

	tmp = *inst;
	while (tmp)
	{
		sort(stk_a, stk_b, tmp->data);
		tmp = tmp->next;
	}
	lstclear(inst);
}

int	isinlst(t_stack *lst, int n)
{
	t_stack	*tmp;
	int		nbr;

	tmp = lst;
	while (tmp)
	{
		nbr = *((int *)tmp->data);
		if (nbr == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
