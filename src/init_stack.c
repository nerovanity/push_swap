/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:43:31 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/15 11:18:27 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}

t_list	*init_stack(int *array, int size)
{
	t_list	*stack;
	t_list	*head;
	int		i;

	i = 0;
	stack = ft_lstnew(array[i++]);
	if (!stack)
		return (NULL);
	head = stack;
	while (i < size)
	{
		head->next = ft_lstnew(array[i++]);
		head = head->next;
	}
	return (stack);
}
