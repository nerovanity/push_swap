/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:19:55 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/11 10:30:01 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_num_in(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == ' ' || str[i] == '-' || str[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

static	int	check_sign(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if ((i > 0 && str[i - 1] != ' ' ) || !str[i + 1])
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_is_num(int ac, char **av)
{
	int		i;
	size_t	len;

	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (!is_num_in(av[i], len))
			return (0);
		if (!check_sign(av[i], len))
			return (0);
		i++;
	}
	return (1);
}
