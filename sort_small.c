/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:40:33 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/07 18:39:12 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack[i].index)
	{
		if (stack[i].index == 1)
			return (stack[i].value);
		i++;
	}
	return (0);
}

void	sort_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a[0].value;
	middle = stack_a[1].value;
	bottom = stack_a[2].value;
	if (top > middle && middle < bottom && top < bottom)
		swap(stack_a, 'a');
	if (top > middle && middle > bottom && top > bottom)
	{
		swap(stack_a, 'a');
		rev_rotate(stack_a, 'a');
	}
	if (top > middle && middle < bottom && top > bottom)
		rotate(stack_a, 'a');
	if (top < middle && middle > bottom && top > bottom)
		rev_rotate(stack_a, 'a');
	if (top < middle && middle > bottom && top < bottom)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
}
