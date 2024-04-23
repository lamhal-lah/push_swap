/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:13:58 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 17:38:13 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	check_if_valid(char *data)
{
	if (ft_strcmp(data, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(data, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(data, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(data, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(data, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(data, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(data, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(data, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(data, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(data, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(data, "rrr\n") == 0)
		return (1);
	return (0);
}

void	sort(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
}

static int	issorted(t_stack *stk_a)
{
	t_stack	*tmp;

	tmp = stk_a;
	while (tmp->next)
	{
		if (*((int *)tmp->data) > *((int *)tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_is_sorted(t_stack **stk_a, t_stack **stk_b)
{
	if (!stk_a || !stk_b)
		return ;
	if (*stk_b)
	{
		lstclear(stk_b);
		write(1, "KO\n", 3);
	}
	else if (issorted(*stk_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lstclear(stk_a);
	exit(0);
}
