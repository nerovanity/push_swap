/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:23:08 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/27 15:14:24 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	max_index(t_list **stack_b, int *max)
{
	t_list	*head;
	int		i;
	int		j;

	j = 0;
	i = 0;
	head = *stack_b;
	*max = head->index;
	head = head->next;
	while (head)
	{
		if (head->index > *max)
		{
			*max = head->index;
			i = j;
		}
		head = head->next;
		j++;
	}
	return (i);
}

static void	sorting(t_list **stack_a, t_list **stack_b, int size)
{
	int		middle;
	int		i;
	int		max;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	middle = size / 2;
	i = max_index(stack_b, &max);
	if (i < middle)
	{
		while ((*stack_b)->index != max)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (i >= middle)
	{
		while ((*stack_b)->index != max)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	sorting(stack_a, stack_b, --size);
}

void	sort100(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 15;
	(void)size;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + j))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	sorting(stack_a, stack_b, size);
}
