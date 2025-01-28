/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:13:17 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/12 15:19:21 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(int *array, int nbr, size_t len, char **args)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == nbr)
		{
			free(array);
			free_array(args);
			p_error();
		}
		i++;
	}
	return (1);
}
