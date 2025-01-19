/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 13:45:52 by ihamani          ###   ########.fr       */
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
		return (NULL);
	len = 0;
	args = fetch_args(ac, av);
	while (args[len])
	{
		len++;
	}
	array = convert_int(args);
	printf("_________________Stack_____________\n");
	stack = init_stack(array, len);
	free(array);
	return (stack);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parse_stack(ac, av);
	stack_b = NULL;
	if (!stack_a)
		p_error();
	sort4(&stack_a, &stack_b);
	print_stack(stack_a);
	write(1, "stack b\n", 9);
	if (stack_b)
		print_stack(stack_b);
	free_stack(&stack_a);
}
