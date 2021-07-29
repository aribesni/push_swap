/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:05 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 19:21:47 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_p_swap    *pile_a;
	t_p_swap    *pile_b;

	pile_a = NULL;
	if (push_swap(&pile_a, argc, argv) == 0)
		return (0);
	if (!(pile_b = malloc(sizeof(pile_a))))
		return (-1);
	ft_exec(&pile_a, &pile_b, argc, argv);
/*    printf("\n");
	while (pile_a)
	{
	    printf("display a : %i\n", pile_a->i);
	    pile_a = pile_a->next;
	}
	printf("\n");
	while (pile_b->next)
	{
	    printf("display b : %i\n", pile_b->i);
		pile_b = pile_b->next;
	}
*/    free(pile_a);
	free(pile_b);
	return (0);
}
