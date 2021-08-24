/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:28 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 18:47:52 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft.h"

typedef struct		s_p_swap
{
	int				i;
	struct s_p_swap	*next;
}					t_p_swap;

typedef struct		s_struc
{
	int				count;
}					t_struct;

void	            ft_add_elem(t_p_swap **pile, int nb);
void	            ft_push(t_p_swap **pile_1, t_p_swap **pile_2, char *str);
void	            ft_reverse_rotate(t_p_swap **pile, char *str);
void	            ft_rotate(t_p_swap **pile, char *str);
void	            ft_swap(t_p_swap **pile, char *str);
int					ft_check_error(t_p_swap **pile_a, int argc, char **argv);
int					ft_check_if_double(t_p_swap **pile_a);
int					ft_check_if_empty(char *str);
int					ft_check_space(int i, int j, char **argv);
int					ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, t_struct *data,
						char **argv);
int					ft_full_pile_in_order(t_p_swap **pile_a, int argc);
int					ft_long_arg(t_p_swap **pile_a, t_struct *data, char **argv, int i);
int					ft_pile_in_order(t_p_swap **pile_a);
int	                ft_return_error(void);
int					push_swap(t_p_swap **pile_a, t_struct *data, int argc, char **argv);
long int	        ft_atoli(const char *str);
char				*ft_fill_str(char **argv, int i, int *j);

#endif
