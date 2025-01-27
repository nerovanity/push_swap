/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:46:09 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/27 10:10:00 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_num(long long r, int *array, char **args)
{
	if (r > (long long)2147483647)
	{
		free(array);
		free_array(args);
		p_error();
	}
	if (r < (long long)-2147483648)
	{
		free(array);
		free_array(args);
		p_error();
	}
}

static void	over(int len, int *array, char **args)
{
	if (len > 12)
	{
		free(array);
		free_array(args);
		p_error();
	}
}

int	ft_atoi(char *s, int *array, char **args)
{
	int					i;
	int					sign;
	long long			r;
	int					len;

	i = 0;
	r = 0;
	sign = 1;
	len = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9'))
	{
		r = (r * 10) + (s[i++] - '0');
		len++;
	}
	over(len, array, args);
	check_num(r * sign, array, args);
	return (r * sign);
}
