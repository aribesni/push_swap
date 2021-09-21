/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:30:23 by aribesni          #+#    #+#             */
/*   Updated: 2021/09/21 10:29:28 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_number(t_p_swap **pile_a, t_p_swap **pile_b, t_struct *data,
	int size)
{
	int			max_a;
	int			max_tmp;
	t_p_swap	*temp;

	max_a = ft_return_max(pile_a);
	while (size--)
	{
		temp = *pile_a;
		while (temp)
		{
			if (temp->i == max_a)
				temp->number = size;
			temp = temp->next;
		}
		temp = *pile_a;
		max_tmp = temp->i;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->i < max_a && max_tmp < max_a && max_tmp < temp->i
				|| max_tmp >= max_a)
				max_tmp = temp->i;
		}
		max_a = max_tmp;
	}
}

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

void	ft_add_elem(t_p_swap **pile, int nb)
{
	t_p_swap	*new_elem;

	new_elem = malloc(sizeof(t_p_swap));
	if (!new_elem)
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
