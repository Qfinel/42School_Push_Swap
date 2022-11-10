/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:40:44 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/09 12:57:29 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack[i].index)
		i++;
	return (i);
}

int	get_i_of_biggest(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (stack[i].index)
	{
		if (stack[i].index == size)
			return (i);
		i++;
	}
	return (i);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack[i].index)
	{
		if (stack[i - 1].value > stack[i].value)
			return (0);
		i++;
	}
	return (1);
}

void	pick_operation(t_stack *stack_a, t_stack *stack_b, int value)
{
	if (stack_a[0].value < value)
		push(stack_b, stack_a, 'b');
	else if (get_next(stack_a, value) < get_stack_size(stack_a) / 2)
	{
		if (get_i_of_biggest(stack_b, get_stack_size(stack_b))
			< get_stack_size(stack_b) / 2)
			rotate_both(stack_a, stack_b);
		else
			rotate(stack_a, 'a');
	}
	else
	{
		if (get_i_of_biggest(stack_b, get_stack_size(stack_b))
			> get_stack_size(stack_b) / 2)
			rev_rotate_both(stack_a, stack_b);
		else
			rev_rotate(stack_a, 'a');
	}
}

void	sorting(t_stack	*stack_a, t_stack *stack_b)
{
	int	size;

	if (is_sorted(stack_a))
	{
		free(stack_a);
		free(stack_b);
		exit(0);
	}
	size = get_stack_size(stack_a);
	if (size == 2)
		swap(stack_a, 'a');
	if (size == 3)
		sort_3(stack_a);
	else
		sort_big(stack_a, stack_b, size);
}
