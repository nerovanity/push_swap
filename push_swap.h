/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:20:03 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/12 15:22:23 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		check_is_num(int ac, char **av);
void	p_error(void);
char	**fetch_args(int ac, char **av);
size_t	ft_strlen(char *str);
char	**ft_split(char const *str, char c);
char	**args_join(char **array1, char **array2);
char	**args_dup(char **array);
char	*ft_strdup(char *s);
int		ft_atoi(char *s, int *array, char **args);
int		*convert_int(char **args);
int		check_dup(int	*array, int nbr, size_t len, char **args);
void	free_array(char	**tmp);

#endif