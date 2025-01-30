/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 15:05:33 by ihamani          ###   ########.fr       */
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

void	pop_moves(t_list **stack_a, t_list **stack_b)
{
	char	**args;
	char	**tmp;
	char	*str;

	args = NULL;
	str = get_next_line(0);
	while (str != NULL)
	{
		check_moves(args, str, stack_a, stack_b);
		tmp = args;
		args = args_join_moves(args, &str);
		free(str);
		str = get_next_line(0);
		if (tmp)
			free_array(tmp);
	}
	if (args)
	{
		read_moves(args, stack_a, stack_b);
		free_array(args);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	stack_a = parse_stack(ac, av);
	stack_b = NULL;
	if (!stack_a)
		p_error();
	len = ft_lstsize(stack_a);
	pop_moves(&stack_a, &stack_b);
	if (check_stack_sort(&stack_a, len))
		write(1, "OK\n", 3);
	else if (!check_stack_sort(&stack_a, len))
		write(1, "KO\n", 3);
	free_stack(&stack_b);
	free_stack(&stack_a);
}
