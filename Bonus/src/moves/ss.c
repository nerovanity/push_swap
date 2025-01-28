/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:12:39 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:51:04 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL || stack_b == NULL
		|| *stack_a == NULL || stack_a == NULL)
		return ;
	sa(stack_a);
	sb(stack_b);
}
