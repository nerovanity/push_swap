/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:32:02 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 15:01:21 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	wrong_move(char **args, char *str, t_list **stack_a, t_list **stack_b)
{
	free(str);
	str = get_next_line(-1);
	free(str);
	if (args)
		free_array(args);
	free_stack(stack_b);
	free_stack(stack_a);
	p_error();
}

void	check_moves(char **args, char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return ;
	else if (ft_strcmp(str, "sb\n") == 0)
		return ;
	else if (ft_strcmp(str, "ss\n") == 0)
		return ;
	else if (ft_strcmp(str, "pa\n") == 0)
		return ;
	else if (ft_strcmp(str, "pb\n") == 0)
		return ;
	else if (ft_strcmp(str, "ra\n") == 0)
		return ;
	else if (ft_strcmp(str, "rb\n") == 0)
		return ;
	else if (ft_strcmp(str, "rr\n") == 0)
		return ;
	else if (ft_strcmp(str, "rra\n") == 0)
		return ;
	else if (ft_strcmp(str, "rrb\n") == 0)
		return ;
	else if (ft_strcmp(str, "rrr\n") == 0)
		return ;
	else
		wrong_move(args, str, stack_a, stack_b);
}

static void	apply_moves(char *str, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
}

void	read_moves(char **args, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (args[i])
	{
		apply_moves(args[i], stack_a, stack_b);
		i++;
	}
}
