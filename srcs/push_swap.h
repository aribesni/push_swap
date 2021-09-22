/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:28 by aribesni          #+#    #+#             */
/*   Updated: 2021/09/22 09:49:13 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_p_swap
{
	int				i;
	int				number;
	struct s_p_swap	*next;
}					t_p_swap;

typedef struct s_struc
{
	int				count;
	int				min;
	int				max;
	int				size_big;
	int				size_small;
	int				*big_half;
	int				*small_half;
}					t_struct;

void				ft_add_elem(t_p_swap **pile, int nb);
void				ft_free_pile(t_p_swap	**pile_a);
void				ft_order_bits(t_p_swap **pile_a, t_p_swap **pile_b,
						int size);
void				ft_push(t_p_swap **pile_1, t_p_swap **pile_2, char *str);
void				ft_putchar(char c);
void				ft_putendl(char *s);
void				ft_putstr(char *str);
void				ft_reverse_rotate(t_p_swap **pile, char *str);
void				ft_rotate(t_p_swap **pile, char *str);
void				ft_set_number(t_p_swap **pile_a, t_p_swap **pile_b,
						t_struct *data, int size);
void				ft_swap(t_p_swap **pile, char *str);
int					ft_atoi(const char *str);
int					ft_check_error(t_p_swap **pile_a, int argc, char **argv);
int					ft_check_if_double(t_p_swap **pile_a);
int					ft_check_if_empty(char *str);
int					ft_check_space(int i, int j, char **argv);
int					ft_exec(t_p_swap **pile_a, t_p_swap **pile_b,
						t_struct *data, char **argv);
int					ft_long_arg(t_p_swap **pile_a, t_struct *data, char **argv,
						int i);
int					ft_pile_in_order(t_p_swap **pile_a);
int					ft_return_error(t_p_swap **pile_a);
int					push_swap(t_p_swap **pile_a, t_struct *data, int argc,
						char **argv);
int					ft_return_max(t_p_swap **pile_a);
int					ft_return_mid(t_p_swap **pile_a, int min, int max);
int					ft_return_min(t_p_swap **pile_a);
int					ft_strlen(const char *str);
long int			ft_atoli(const char *str);
char				*ft_fill_str(char **argv, int i, int *j, int k);

#endif
