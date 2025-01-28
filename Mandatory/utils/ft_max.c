/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:44:34 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 13:44:51 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(t_list **stack_a)
{
	int		max;
	t_list	*head;

	head = *stack_a;
	max = (head->nbr);
	head = head->next;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
	}
	return (max);
}
