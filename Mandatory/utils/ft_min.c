/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:45:31 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 13:45:58 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min(t_list **stack_a)
{
	int		min;
	t_list	*head;

	head = *stack_a;
	min = (head->nbr);
	head = head->next;
	while (head)
	{
		if (head->nbr < min)
			min = head->nbr;
		head = head->next;
	}
	return (min);
}
