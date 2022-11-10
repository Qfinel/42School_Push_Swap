/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtsizik <jtsizik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:56:30 by jtsizik           #+#    #+#             */
/*   Updated: 2022/11/10 12:07:43 by jtsizik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int		value;
	int		index;
}	t_stack;

void	push_swap(int len, char **argv);
void	swap(t_stack *stack, char c);
int		contains_space(char *str);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
int		get_arg_len(char **argv);
int		check_input(char *str);
void	rotate(t_stack *stack, char c);
void	rev_rotate(t_stack *stack, char c);
void	rev_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	pick_operation(t_stack *stack_a, t_stack *stack_b, int value);
int		get_stack_size(t_stack *stack);
void	check_for_dups(t_stack *stack);
void	get_indexes(t_stack *stack);
int		get_splits(int size);
void	push(t_stack *stack_a, t_stack *stack_b, char c);
void	get_values(t_stack *stack, char **argv);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	sorting(t_stack	*stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
void	sort_3(t_stack *stack_a);
void	move_src(t_stack *src);
void	sort_big(t_stack *stack_a, t_stack *stack_b, int size);
void	push_chunks(t_stack *stack_a, t_stack *stack_b, int size);
void	sort_real_big(t_stack *stack_a, t_stack *stack_b, int size);
int		get_i_of_biggest(t_stack *stack_b, int size);
void	push_back(t_stack *stack_a, t_stack *stack_b);
int		get_next(t_stack *stack, int value);
int		find_value(t_stack *stack, int mid);

#endif