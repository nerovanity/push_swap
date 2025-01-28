/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:38:48 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:44:13 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*nt;

	if (stack == NULL || *stack == NULL)
		return ;
	head = *stack;
	while (head)
	{
		nt = head->next;
		head->nbr = 0;
		free(head);
		head = nt;
	}
	*stack = NULL;
}
