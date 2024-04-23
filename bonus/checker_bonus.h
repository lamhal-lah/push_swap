/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:33:33 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/23 16:54:32 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "getn/get_next_line.h"

typedef struct s_stack
{
	void			*data;
	struct s_stack	*next;
}	t_stack;

void	ft_free(char **str, int l);
char	**ft_split(char *s, char c);
t_stack	*lstnew(void *content);
void	lstclear(t_stack **stk);
void	addback(t_stack **stk, t_stack *node);
void	addfront(t_stack **stk, t_stack *node);
int		isinlst(t_stack *lst, int n);
void	ft_fillstack(t_stack **stk_a, char **av);
int		ft_strcmp(char *str1, char *str2);
int		check_if_valid(char *line);
void	sa(t_stack **stk_a);
void	sb(t_stack **stk_b);
void	ss(t_stack **stk_a, t_stack **stk_b);
void	pa(t_stack **stk_a, t_stack **stk_b);
void	pb(t_stack **stk_a, t_stack **stk_b);
void	ra(t_stack **stk_a);
void	rb(t_stack **stk_b);
void	rr(t_stack **stk_a, t_stack **stk_b);
void	rra(t_stack **stk_a);
void	rrb(t_stack **stk_b);
void	rrr(t_stack **stk_a, t_stack **stk_b);
void	sort(t_stack **stk_a, t_stack **stk_b, char *data);
void	fill_list_instr(t_stack **inst, t_stack **stk_a);
void	execut_instr(t_stack **stk_a, t_stack **stk_b, t_stack **inst);
void	check_is_sorted(t_stack **stk_a, t_stack **stk_b);

#endif