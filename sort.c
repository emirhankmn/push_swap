/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:19:07 by eakman            #+#    #+#             */
/*   Updated: 2023/12/14 20:36:15 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_push(t_stack *stack, int len, int flag)
{
	if (flag == 0)
		pb(stack, 0);
	else
		pa(stack, 0);
	len--;
	return (len);
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1]
		&& stack->a[0] < stack->a[2] && stack->a[1] < stack->a[2])
		sa(stack, 0);
	if (stack->a[0] > stack->a[1]
		&& stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	if (stack->a[0] > stack->a[1]
		&& stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2])
		ra(stack, 0);
	if (stack->a[0] < stack->a[1]
		&& stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		ra(stack, 0);
	}
	if (stack->a[0] < stack->a[1]
		&& stack->a[0] > stack->a[2] && stack->a[1] > stack->a[2])
		rra(stack, 0);
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_check_sort(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
		{
			sa(stack, 0);
		}
		else if (size == 3)
		{
			ft_sort_three(stack);
		}
		else
		{
			ft_quicksort_a(stack, size, 0);
		}
	}
	return (0);
}
