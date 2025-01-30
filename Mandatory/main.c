/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 13:11:16 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len <= 3)
		tiny_sort(stack_a);
	else if (len == 4)
		sort4(stack_a, stack_b);
	else if (len == 5)
		sort5(stack_a, stack_b);
	else if (len > 5 && len <= 100)
		sort100(stack_a, stack_b, len);
	else if (len > 100)
		sort500(stack_a, stack_b, len);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parse_stack(ac, av);
	stack_b = NULL;
	if (!stack_a)
		p_error();
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
}
