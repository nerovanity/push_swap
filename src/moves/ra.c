/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:28 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 11:20:46 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*top;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	if (!(*stack_a)->next)
		return ;
	head = *stack_a;
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	while (head->next)
		head = head->next;
	head->next = top;
	top->next = NULL;
	write(1, "ra\n", 3);
}
