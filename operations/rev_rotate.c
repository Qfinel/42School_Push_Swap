/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:39:38 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/07 18:28:51 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_stack *stack, char c)
{
	t_stack	tmp;
	int		i;

	i = get_stack_size(stack) - 1;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rev_rotate(stack_a, 0);
	rev_rotate(stack_b, 0);
	ft_printf("rrr\n");
}
