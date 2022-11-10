/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:38:54 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/07 18:28:44 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack, char c)
{
	t_stack	tmp;
	int		i;

	tmp = stack[0];
	i = 1;
	while (stack[i].index)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	i--;
	stack[i] = tmp;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_printf("rr\n");
}
