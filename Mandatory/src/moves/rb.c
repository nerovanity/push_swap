/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:10:53 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 11:21:10 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rb(t_list **stack_b)
{
	t_list	*head;
	t_list	*top;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	if (!(*stack_b)->next)
		return ;
	head = *stack_b;
	top = *stack_b;
	*stack_b = (*stack_b)->next;
	while (head->next)
	{
		head = head->next;
	}
	head->next = top;
	top->next = NULL;
	write(1, "rb\n", 3);
}
