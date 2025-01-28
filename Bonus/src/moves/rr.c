/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:12:39 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 10:50:48 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_bonus.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL || stack_b == NULL
		|| *stack_a == NULL || stack_a == NULL)
		return ;
	ra(stack_a);
	rb(stack_b);
}
