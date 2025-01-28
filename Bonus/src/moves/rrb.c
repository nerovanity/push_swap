/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:27:50 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:50:53 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

void	rrb(t_list **stack_b)
{
	t_list	*head;
	t_list	*tmp;

	if (*stack_b == NULL || stack_b == NULL)
		return ;
	if (!(*stack_b)->next)
		return ;
	head = *stack_b;
	while (head->next->next)
		head = head->next;
	tmp = head->next;
	head->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}
