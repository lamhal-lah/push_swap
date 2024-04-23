/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:30:47 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/24 15:13:19 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*inst;

	stk_a = NULL;
	stk_b = NULL;
	inst = NULL;
	if (ac == 1)
		exit(0);
	ft_fillstack(&stk_a, av);
	fill_list_instr(&inst, &stk_a);
	execut_instr(&stk_a, &stk_b, &inst);
	check_is_sorted(&stk_a, &stk_b);
	exit (0);
}
