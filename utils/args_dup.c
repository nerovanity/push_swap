/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:48:51 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/12 10:52:02 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count(char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	**args_dup(char **array)
{
	char	**r_array;
	int		i;

	if (!array)
		return (NULL);
	i = 0;
	r_array = malloc((count(array) + 1) * sizeof(char *));
	if (!r_array)
		return (NULL);
	while (array[i])
	{
		r_array[i] = ft_strdup(array[i]);
		i++;
	}
	array[i] = NULL;
	return (r_array);
}
