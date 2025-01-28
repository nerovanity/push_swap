/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:57:26 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:50:59 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

void	sa(t_list **stack)
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
}
