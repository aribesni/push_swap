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

void	            ft_add_elem(t_p_swap **pile, int nb);
void	            ft_push(t_p_swap **pile_1, t_p_swap **pile_2, char *str);
void	            ft_reverse_rotate(t_p_swap **pile, char *str);
void	            ft_rotate(t_p_swap **pile, char *str);
void	            ft_swap(t_p_swap **pile, char *str);
int					ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, int argc,
						char **argv);
int					ft_full_pile_in_order(t_p_swap **pile_a, int argc);
int					ft_pile_in_order(t_p_swap **pile_a);
int	                ft_return_error(void);
int					push_swap(t_p_swap **pile_a, int argc, char **argv);
long int	        ft_atoli(const char *str);

#endif
