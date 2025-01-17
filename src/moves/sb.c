/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:11:12 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 11:35:01 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sb(t_list **stack)
{
	t_list	*head;

	if (stack == NULL || *stack == NULL)
		return ;
	if (!(*stack)->next)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	head->next = (*stack)->next;
	(*stack)->next = head;
	write(1, "sb\n", 3);
}
