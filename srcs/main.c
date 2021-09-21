/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:05 by aribesni          #+#    #+#             */
/*   Updated: 2021/08/25 09:13:30 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_p_swap		*pile_a;
	t_p_swap		*pile_b;
	t_p_swap		*temp;
	t_struct		data;

	pile_a = NULL;
	data.max = 0;
	data.count = 0;
	data.big_half = NULL;
	data.small_half = NULL;
	if (push_swap(&pile_a, &data, argc, argv) == 0)
		return (0);
	pile_b = malloc(sizeof(t_p_swap));
	if (!pile_b)
		return (-1);
	pile_b->next = NULL;
	ft_exec(&pile_a, &pile_b, &data, argv);
	while (pile_a)
	{
		temp = pile_a;
		pile_a = pile_a->next;
		free(temp);
	}
	free(pile_b);
	return (0);
}
