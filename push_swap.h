/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:50:27 by eakman            #+#    #+#             */
/*   Updated: 2023/12/20 17:38:11 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

int		av_control(char **av);
int		ft_check_sort(int *stack_a, int size, int flag);
void	ft_repeat_control(int *stack, int size);

int		ft_sort(t_stack *stack, int size);
int		ft_push(t_stack *stack, int len, int flag);
int		ft_quicksort_a(t_stack *stack, int len, int count);
int		ft_quicksort_b(t_stack *stack, int len, int count);
void	ft_sort_three(t_stack *stack);
void	ft_sort_int_tmp(int *tmp_stack, int size);

int		ft_strlen1(char **s);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str, int *stack);
char	*get_next_line(int fd);
char	*ft_new_left_str(char *left_str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_read_to_left_str(int fd, char *left_str);
void	ft_error(int *stack);
void	ft_bzero(void *s, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);

void	sa(t_stack	*stack, int print);
void	pa(t_stack	*stack, int print);
void	ra(t_stack	*stack, int print);
void	rra(t_stack *stack, int print);

void	pb(t_stack	*stack, int print);
void	sb(t_stack	*stack, int print);
void	rb(t_stack	*stack, int print);
void	rrb(t_stack	*stack, int print);

void	rrr(t_stack *stack, int print);
#endif