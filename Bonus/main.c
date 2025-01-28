/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 11:52:00 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*parse_stack(int ac, char **av)
{
	char	**args;
	int		len;
	int		*array;
	t_list	*stack;

	if (ac < 2)
		exit(0);
	len = 0;
	args = fetch_args(ac, av);
	while (args[len])
	{
		len++;
	}
	array = convert_int(args);
	stack = init_stack(array, len);
	free(array);
	return (stack);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		len;

	len = 0;
	head = lst;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

static	void	wrong_move(char *str, t_list **stack_a, t_list **stack_b)
{
	free(str);
	str = get_next_line(-1);
	free(str);
	free_stack(stack_b);
	free_stack(stack_a);
	p_error();
}

static void	read_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		wrong_move(str, stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;
	int		len;

	stack_a = parse_stack(ac, av);
	stack_b = NULL;
	if (!stack_a)
		p_error();
	len = ft_lstsize(stack_a);
	str = get_next_line(0);
	while (str != NULL)
	{
		read_moves(str, &stack_a, &stack_b);
		free(str);
		str = get_next_line(0);
	}
	if (check_stack_sort(&stack_a, len))
		write(1, "OK\n", 3);
	else if (!check_stack_sort(&stack_a, len))
		write(1, "KO\n", 3);
	free(str);
	free_stack(&stack_b);
	free_stack(&stack_a);
}
