/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 13:17:51 by ihamani          ###   ########.fr       */
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

void	sort2(t_list **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}

void	sort3(t_list **stack_a, t_list **stack_b)
{
	// edge cases
	pb(stack_a, stack_b);
	sort2(stack_a);
	if ((*stack_b)->nbr > (*stack_a)->next->nbr)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else
	{
		if ((*stack_b)->nbr < (*stack_a)->nbr)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			rra(stack_a);
		}
		else
		{
			pa(stack_a, stack_b);
			sa(stack_a);
		}
	}
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	sort3(stack_a, stack_b);
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
