/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:48:01 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 14:00:03 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = ft_min(stack_a);
	if ((*stack_a)->nbr == min)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->nbr == min)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->nbr == min)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		if ((*stack_a)->nbr != min)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
