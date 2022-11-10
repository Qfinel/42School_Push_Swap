/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:54:33 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/08 12:26:56 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *dest, t_stack *src, char c)
{
	int	i;

	i = 0;
	if (dest[0].index)
	{
		i = get_stack_size(dest);
		while (i > 0)
		{
			dest[i] = dest[i - 1];
			i--;
		}
	}
	dest[0].value = src[0].value;
	move_src(src);
	dest[0].index = 1;
	if (src[0].index)
		get_indexes(src);
	get_indexes(dest);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	move_src(t_stack *src)
{
	int	i;

	i = 0;
	while (src[i].index)
	{
		src[i] = src[i + 1];
		i++;
	}
}
