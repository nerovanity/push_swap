/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:48:51 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/14 10:59:08 by ihamani          ###   ########.fr       */
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
	size_t	len;

	if (!array)
		return (NULL);
	len = count(array);
	r_array = malloc((len + 1) * sizeof(char *));
	if (!r_array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		r_array[i] = ft_strdup(array[i]);
		if (!r_array[i])
			return (free_array(r_array), NULL);
		i++;
	}
	r_array[i] = NULL;
	return (r_array);
}


