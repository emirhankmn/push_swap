/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:43:37 by eakman            #+#    #+#             */
/*   Updated: 2023/12/24 14:03:10 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *stack, int print)
{
	int	tmp;

	tmp = 0;
	if (stack->size_a < 2)
	{
		write(1, "A few argument", 14);
		return ;
	}
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (!print)
		write(1, "sa\n", 3);
}

void	rra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	if (!print)
		write(1, "rra\n", 4);
}

void	ra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	tmp = stack->a[0];
	i = 1;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (!print)
	{
		write(1, "ra\n", 3);
	}
}

void	pa(t_stack *stack, int print)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
		{
			stack->a[i] = stack->a[i - 1];
		}
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
		{
			stack->b[i] = stack->b[i + 1];
		}
		if (!print)
		{
			write(1, "pa\n", 3);
		}
	}
	else
		return ;
}

void	rrr(t_stack *stack, int print)
{
	rra(stack, 1);
	rrb(stack, 1);
	if (!print)
		write(1, "rrr\n", 3);
	return ;
}
