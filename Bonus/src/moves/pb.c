/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:41:27 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:50:39 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;
	t_list	*head_a;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	head_b = *stack_b;
	*stack_b = head_a;
	(*stack_b)->next = head_b;
}
