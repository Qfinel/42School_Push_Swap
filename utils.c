/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:31:54 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/08 13:18:54 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arg_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	check_input(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_itoa(ft_atoi(&str[i]));
	while (str[i])
	{
		if (str[i] != tmp[i])
		{
			free(tmp);
			return (0);
		}
		i++;
	}
	free(tmp);
	return (1);
}

void	check_for_dups(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i].index)
	{
		while (stack[j].index)
		{
			if (stack[i].value == stack[j].value && i != j)
			{
				free(stack);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_values(t_stack *stack, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!check_input(argv[i]))
		{
			free(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		stack[i].value = ft_atoi(argv[i]);
		stack[i].index = 1;
		i++;
	}
	check_for_dups(stack);
}

void	get_indexes(t_stack *stack)
{
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (stack[j].index)
	{
		stack[j].index = 1;
		while (stack[n].index)
		{
			if (stack[j].value > stack[n].value)
				stack[j].index++;
			n++;
		}
		n = 0;
		j++;
	}
}
