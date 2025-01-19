/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:40:48 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/19 10:51:16 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	arraylen(char **args)
{
	size_t	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}

void	is_sorted(int *array)
{
	free(array);
	exit(0);
}

int	*convert_int(char **args)
{
	int		*array;
	size_t	len;
	size_t	i;
	int		nbr;

	if (!args)
		return (0);
	len = arraylen(args);
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < len)
	{
		nbr = ft_atoi(args[i], array, args);
		check_dup(array, nbr, i, args);
		array[i] = nbr;
		i++;
	}
	free_array(args);
	if (check_sorted(array, len))
		is_sorted(array);
	return (array);
}
