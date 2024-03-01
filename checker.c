/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:47:27 by ezcakir           #+#    #+#             */
/*   Updated: 2023/12/20 17:43:50 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	free_error(t_stack *stack, int num)
{
	free(stack->a);
	free(stack->b);
	if (num)
		write(1, "Error\n", 6);
	exit(1);
}

void	exec_a(t_stack *stack, char *a)
{
	if (!ft_strcmp(a, "sa\n"))
		sa(stack, 1);
	else if (!ft_strcmp(a, "sb\n"))
		sb(stack, 1);
	else if (!ft_strcmp(a, "ra\n"))
		ra(stack, 1);
	else if (!ft_strcmp(a, "rb\n"))
		rb(stack, 1);
	else if (!ft_strcmp(a, "rra\n"))
		rra(stack, 1);
	else if (!ft_strcmp(a, "rrb\n"))
		rrb(stack, 1);
	else if (!ft_strcmp(a, "pa\n"))
		pa(stack, 1);
	else if (!ft_strcmp(a, "pb\n"))
		pb(stack, 1);
	else if (!ft_strcmp(a, "rrr\n"))
		rrr(stack, 1);
	else
		free_error(stack, 1);
}

void	ft_checkchecker(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exec_a(stack, str);
		free(str);
		str = get_next_line(0);
	}
	if (ft_check_sort(stack->a, stack->size_a, 0) && stack->size_b == 0)
		write(1, "\033[0;32mOK\n", 10);
	else
		write(1, "\033[0;32mKO\n", 10);
	free_error(stack, 0);
}

void	ft_checker(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen1(av);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free (stack.a);
		return ;
	}
	stack.size_b = 0;
	while (i < size)
	{
		stack.a[i] = ft_atoi(av[i], stack.a);
		i++;
	}
	ft_repeat_control(stack.a, size);
	ft_checkchecker(&stack);
}

int	main(int ac, char **av)
{
	char	**data;

	data = NULL;
	if (av_control(av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			data = ft_split(*av, ' ');
			ft_checker(data);
		}
		else
			ft_checker(av);
	}
	if (data)
		free(data);
	return (0);
}
