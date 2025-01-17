/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:06:03 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/17 12:10:21 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list *head)
{
	if (head == NULL)
		return ;
	while (head)
	{
		printf("Number : %d\n", head->nbr);
		head = head->next;
	}
}
