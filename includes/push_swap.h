/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:57:13 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 17:57:14 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct      s_p_swap
{
    int             i;
    struct s_p_swap *next;
}                   t_p_swap;

int                 push_swap(t_p_swap **pile_a, int argc, char **argv);
void                ft_exec(t_p_swap **pile_a, t_p_swap **pile_b);

#endif
