/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:10:34 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/27 11:19:51 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	search(int *array, int nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nbr == array[i])
			return (i);
		i++;
	}
	return (0);
}

void	index_stack(t_list **stack_a, int *array, int size)
{
	t_list	*head;

	head = *stack_a;
	bubble_sort(array, size);
	while (head)
	{
		head->index = search(array, head->nbr, size);
		head = head->next;
	}
}
