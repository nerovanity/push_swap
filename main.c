/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/12 15:09:44 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	int		i;
	int		*array;
	int		j;

	if (ac < 2)
		return (1);
	i = 0;
	j = 0;
	args = fetch_args(ac, av);
	while (args[i])
	{
		i++;
	}
	array = convert_int(args);
	printf("_________________nums_____________\n");
	while (j < i)
		printf("%d\n", array[j++]);
	free(array);

}
