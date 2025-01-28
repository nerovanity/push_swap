/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:25 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 11:22:40 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_stack_sort(t_list **stack_a, int len)
{
	t_list	*head;
	int		j;

	if (*stack_a == NULL || stack_a == NULL)
		return (0);
	j = 1;
	head = *stack_a;
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
		j++;
	}
	if (j != len)
		return (0);
	return (1);
}
