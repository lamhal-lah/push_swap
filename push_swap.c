/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:50 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 16:07:11 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ac == 1)
		exit (0);
	ft_fillstack(&stk_a, av);
	if (issorted(stk_a) == 1)
		exit (0);
	sort(&stk_a, &stk_b);
	exit (0);
}
