/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:46:13 by eakman            #+#    #+#             */
/*   Updated: 2023/12/14 19:39:43 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_error(int *stack)
{
	free (stack);
	write(1, "Error\n", 6);
	exit (1);
}

int	av_control(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], "") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_repeat_control(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				ft_error(stack);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ft_check_sort(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack_a[i - 1] > stack_a[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack_a[i - 1] < stack_a[i])
				return (0);
			i++;
		}
		return (1);
	}
}
