/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:58 by lamhal            #+#    #+#             */
/*   Updated: 2024/02/24 16:04:18 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				id;
	struct s_stack	*next;
}	t_stack;

void	ft_free(char **str, int l);
char	**ft_split(char *s, char c);
t_stack	*lstnew(int val);
void	addback(t_stack **stk, t_stack *node);
void	addfront(t_stack **stk, t_stack *node);
void	lstclear(t_stack **stk);
int		isinlst(t_stack *lst, int n);
void	ft_fillstack(t_stack **a, char **av);
void	ft_putchar(char *str);
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
int		issorted(t_stack *stk_a);
void	indexer(t_stack *stk, t_stack *node);
int		stksize(t_stack *stk);
void	push_chunk(t_stack **stk_a, t_stack **stk_b, int size, int div);
int		find(t_stack *stk, int id);
void	pushback(t_stack **stk_a, t_stack **stk_b, int size);
void	lstclear(t_stack **stk);
void	sort(t_stack **stk_a, t_stack **stk_b);

#endif