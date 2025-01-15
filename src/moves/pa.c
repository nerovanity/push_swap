/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:50 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/15 13:41:11 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	t_list	*head_a;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	head_b = *stack_b;
	*stack_b = (*stack_b)->next;
	head_a = *stack_a;
	*stack_a = head_b;
	(*stack_a)->next = head_a;
	write(1, "pa\n", 3);
}
