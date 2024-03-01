/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:39:51 by eakman            #+#    #+#             */
/*   Updated: 2023/12/14 17:11:25 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pb(t_stack *stack, int print)
{
	int	i;

	i = 0;
	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
		{
			stack->b[i] = stack->b[i - 1];
		}
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
		{
			stack->a[i] = stack->a[i + 1];
		}
		if (!print)
		{
			write(1, "pb\n", 3);
		}
	}
}

void	sb(t_stack	*stack, int print)
{
	int	tmp;

	tmp = 0;
	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (!print)
		write(1, "sb\n", 3);
}

void	rb(t_stack	*stack, int print)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (!print)
		write(1, "rb\n", 3);
}

void	rrb(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	if (!print)
		write(1, "rrb\n", 4);
}
