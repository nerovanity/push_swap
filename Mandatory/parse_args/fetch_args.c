/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:15 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/30 10:14:29 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p_error(void)
{
	const char	*error_message;

	error_message = "Error\n";
	write(2, error_message, 6);
	exit(1);
}

void	free_array(char	**tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	check_empty_arg(char *str, char **args)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
	{
		if (args)
			free_array(args);
		p_error();
	}
}

char	**fetch_args(int ac, char **av)
{
	char	**args;
	int		i;
	char	**tmp;
	char	**tmp_split;

	i = 1;
	if (!check_is_num(ac, av))
		p_error();
	args = NULL;
	while (i < ac)
	{
		tmp = args;
		check_empty_arg(av[i], args);
		tmp_split = ft_split(av[i], ' ');
		args = args_join(args, tmp_split);
		if (tmp)
			free_array(tmp);
		free_array(tmp_split);
		i++;
	}
	return (args);
}
