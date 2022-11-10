/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:19:54 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/09 12:54:14 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack[i].index)
	{
		if (stack[i].value < value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_value(t_stack *stack, int mid)
{
	int	i;

	i = 0;
	while (stack[i].index)
	{
		if (stack[i].index == mid)
			return (stack[i].value);
		i++;
	}
	return (0);
}

void	push_chunks(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	value;
	int	mid;

	mid = size / 2;
	value = find_value(stack_a, mid);
	while (stack_a[3].index)
	{
		if (is_sorted(stack_a) && get_next(stack_a, value) == -1)
			break ;
		if (get_next(stack_a, value) == -1)
		{
			mid = get_stack_size(stack_a) / 2;
			value = find_value(stack_a, mid);
		}
		pick_operation(stack_a, stack_b, value);
	}
	if (!is_sorted(stack_a))
		sort_3(stack_a);
}

void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	while (stack_b[0].index)
	{
		size = get_stack_size(stack_b);
		if (stack_b[0].index == size)
			push(stack_a, stack_b, 'a');
		else if (get_i_of_biggest(stack_b, size) < size / 2)
			rotate(stack_b, 'b');
		else
			rev_rotate(stack_b, 'b');
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 100)
	{
		push_chunks(stack_a, stack_b, size);
		push_back(stack_a, stack_b);
	}
	if (size > 100)
		sort_real_big(stack_a, stack_b, size);
}
