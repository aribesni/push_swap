/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:24:21 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 19:24:23 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_p_swap **pile, char *str)
{
	t_p_swap	*last;
	t_p_swap	*second_last;

	last = *pile;
	second_last = *pile;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *pile;
	*pile = last;
	ft_putendl(str);
}

void	ft_rotate(t_p_swap **pile, char *str)
{
	t_p_swap	*first;
	t_p_swap	*last;

	first = *pile;
	last = *pile;
	while (last->next)
		last = last->next;
	*pile = first->next;
	first->next = NULL;
	last->next = first;
	ft_putendl(str);
}

void	ft_push(t_p_swap **pile_1, t_p_swap **pile_2, char *str)
{
	t_p_swap	*temp_1;
	t_p_swap	*temp_2;

	temp_1 = *pile_1;
	*pile_1 = temp_1->next;
	temp_2 = *pile_2;
	*pile_2 = temp_1;
	temp_1->next = temp_2;
	ft_putendl(str);
}

void	ft_swap(t_p_swap **pile, char *str)
{
	t_p_swap	*temp_1;
	t_p_swap	*temp_2;
	t_p_swap	*temp_3;

	temp_1 = *pile;
	temp_2 = temp_1->next;
	temp_3 = temp_2->next;
	*pile = temp_1->next;
	temp_1->next = temp_3;
	temp_2->next = temp_1;
	ft_putendl(str);
}