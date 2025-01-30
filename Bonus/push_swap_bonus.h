/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:03 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/28 14:51:04 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}	t_list;

int		check_is_num(int ac, char **av);
void	p_error(void);
char	**fetch_args(int ac, char **av);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *str, char c);
char	**args_join(char **array1, char **array2);
char	**args_dup(char **array);
char	*ft_strdup(const char *s);
int		ft_atoi(char *s, int *array, char **args);
int		*convert_int(char **args);
int		check_dup(int	*array, int nbr, size_t len, char **args);
void	free_array(char	**tmp);
t_list	*init_stack(int *array, int size);
t_list	*ft_lstnew(int content);
int		check_sorted(int *array, int size);
void	free_stack(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		check_stack_sort(t_list **stack_a, int len);
int		ft_strcmp(char *s1, char *s2);
int		ft_lstsize(t_list *lst);
void	check_moves(char **args, char *str, t_list **stack_a, t_list **stack_b);
void	read_moves(char **args, t_list **stack_a, t_list **stack_b);
char	**args_join_moves(char **array1, char **array2);

#endif