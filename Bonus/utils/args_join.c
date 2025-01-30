/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:33:05 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/30 10:08:30 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static size_t	count_args(char **array1, char **array2)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	i = 0;
	j = 0;
	while (array1[i])
	{
		len++;
		i++;
	}
	while (array2[j])
	{
		len++;
		j++;
	}
	return (len);
}

static size_t	count_arg(char **array1)
{
	size_t	len;

	len = 0;
	while (array1[len])
	{
		len++;
	}
	return (len);
}

char	**args_join(char **array1, char **array2)
{
	char	**r_array;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!array1 && !array2)
		return (NULL);
	if (!array1)
		return (args_dup(array2));
	if (!array2)
		return (args_dup(array1));
	r_array = malloc((count_args(array1, array2) + 1) * sizeof(char *));
	if (!r_array)
		return (NULL);
	while (array1[i])
	{
		r_array[i] = ft_strdup(array1[i]);
		i++;
	}
	while (array2[j])
		r_array[i++] = ft_strdup(array2[j++]);
	r_array[i] = NULL;
	return (r_array);
}

char	**args_join_moves(char **array1, char **array2)
{
	char	**r_array;
	size_t	i;

	i = 0;
	if (!array1 && !array2)
		return (NULL);
	if (!array1)
		return (args_dup(array2));
	if (!array2)
		return (args_dup(array1));
	r_array = malloc((count_arg(array1) + 2) * sizeof(char *));
	if (!r_array)
		return (NULL);
	while (array1[i])
	{
		r_array[i] = ft_strdup(array1[i]);
		i++;
	}
	r_array[i++] = ft_strdup(array2[0]);
	r_array[i] = NULL;
	return (r_array);
}
