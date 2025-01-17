/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:23:30 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 11:31:44 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tmp;

	if (*stack_a == NULL || stack_a == NULL)
		return ;
	if (!(*stack_a)->next)
		return ;
	head = *stack_a;
	while (head->next->next)
		head = head->next;
	tmp = head->next;
	head->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}
