/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:57:26 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/15 13:16:09 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_list **stack)
{
	t_list	*head;

	head = *stack;
	*stack = (*stack)->next;
	head->next = (*stack)->next;
	(*stack)->next = head;
	write(1, "sa\n", 3);
}
