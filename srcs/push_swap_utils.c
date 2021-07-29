/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:30:23 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 19:30:25 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pile_in_order(t_p_swap **pile_a)
{
	int			nb;
	t_p_swap	*temp;

	temp = *pile_a;
	nb = temp->i;
	while (temp->next)
	{
		temp = temp->next;
		if (nb > temp->i)
			return (0);
		nb = temp->i;
	}
	return (1);
}

int	ft_full_pile_in_order(t_p_swap **pile_a, int argc)
{
	int			nb;
	t_p_swap	*temp;

	temp = *pile_a;
	nb = temp->i;
	while (temp->next)
	{
		temp = temp->next;
		if (nb > temp->i)
			return (0);
		nb = temp->i;
		argc--;
	}
	if (argc > 0)
		return (0);
	return (1);
}

void	ft_add_elem(t_p_swap **pile, int nb)
{
	t_p_swap	*new_elem;

	if (!(new_elem = malloc(sizeof(t_p_swap))))
		return ;
	new_elem->i = nb;
	new_elem->next = *pile;
	*pile = new_elem;
}

long int	ft_atoli(const char *str)
{
	int			j;
	long int	k;

	j = 1;
	k = 0;
	while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = -j;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		k = k * 10 + (*str - 48);
		str++;
	}
	return (j * k);
}

int	ft_return_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}