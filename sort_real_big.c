/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_real_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:16:38 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/09 12:55:49 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_splits(int size)
{
	int	chunk_size;

	chunk_size = 5;
	while (size >= 150)
	{
		chunk_size += 2;
		size -= 150;
	}
	return (chunk_size);
}

void	sort_real_big(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	value;
	int	mid;

	mid = size / get_splits(size);
	value = find_value(stack_a, mid);
	while (stack_a[mid].index)
	{
		if (is_sorted(stack_a))
			break ;
		if (get_next(stack_a, value) == -1)
			value = find_value(stack_a, mid);
		pick_operation(stack_a, stack_b, value);
	}
	if (!is_sorted(stack_a))
		push_chunks(stack_a, stack_b, get_stack_size(stack_a));
	push_back(stack_a, stack_b);
}
