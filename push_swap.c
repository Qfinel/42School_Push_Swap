/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:56:12 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/10 12:07:29 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	push_swap(int len, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_calloc(len, sizeof(t_stack));
	if (!stack_a)
		exit(1);
	get_values(stack_a, argv);
	stack_b = ft_calloc(len, sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		exit(1);
	}
	get_indexes(stack_a);
	sorting(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	int		len;

	if (argc == 1)
		return (0);
	argv++;
	if (argc == 2 && contains_space(argv[0]))
		argv = ft_split(argv[0], ' ');
	len = get_arg_len(argv);
	if (len < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	push_swap(len, argv);
	return (0);
}
