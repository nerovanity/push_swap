/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:43:17 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 13:43:45 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	tiny_sort(t_list **stack_a)
{
	int	max;

	max = ft_max(stack_a);
	if ((*stack_a)->nbr == max)
		ra(stack_a);
	else if ((*stack_a)->next->nbr == max)
		rra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}
