/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:40:48 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/12 15:23:11 by ihamani          ###   ########.fr       */
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
	return (array);
}
