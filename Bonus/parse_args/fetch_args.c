/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:15 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/27 17:24:13 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	p_error(void)
{
	const char	*red;
	const char	*reset;
	const char	*error_message;

	red = "\033[31m";
	reset = "\033[0m";
	error_message = "Error\n";
	write(2, red, 5);
	write(2, error_message, 6);
	write(2, reset, 4);
	exit(1);
}

void	free_array(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	check_empty_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		p_error();
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
		check_empty_arg(av[i]);
		tmp_split = ft_split(av[i], ' ');
		args = args_join(args, tmp_split);
		if (tmp)
			free_array(tmp);
		free_array(tmp_split);
		i++;
	}
	return (args);
}
