/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:12 by aribesni          #+#    #+#             */
/*   Updated: 2021/09/21 10:31:49 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_is_3(t_p_swap **pile_a)
{
	int			min;
	int			mid;
	int			max;

	min = ft_return_min(pile_a);
	max = ft_return_max(pile_a);
	mid = ft_return_mid(pile_a, min, max);
	if ((*pile_a)->i == min)
	{
		ft_reverse_rotate(pile_a, "rra");
		ft_swap(pile_a, "sa");
	}
	if ((*pile_a)->i == mid && (*pile_a)->next->i == min)
		ft_swap(pile_a, "sa");
	else if ((*pile_a)->i == mid && (*pile_a)->next->i != min)
		ft_reverse_rotate(pile_a, "rra");
	if ((*pile_a)->i == max && (*pile_a)->next->i == min)
		ft_rotate(pile_a, "ra");
	else if ((*pile_a)->i == max && (*pile_a)->next->i != min)
	{
		ft_swap(pile_a, "sa");
		ft_reverse_rotate(pile_a, "rra");
	}
	return (1);
}

int	ft_count_is_4(t_p_swap **pile_a, t_p_swap **pile_b)
{
	t_p_swap	*temp;

	while ((*pile_a)->number != 0)
		ft_reverse_rotate(pile_a, "rra");
	if ((*pile_a)->next->number == 0)
		ft_rotate(pile_a, "ra");
	else
		while ((*pile_a)->number != 0)
			ft_reverse_rotate(pile_a, "rra");
	if (ft_pile_in_order(pile_a) == 1)
		return (1);
	ft_push(pile_a, pile_b, "pb");
	ft_count_is_3(pile_a);
	ft_push(pile_b, pile_a, "pa");
	return (1);
}

int	ft_count_is_5(t_p_swap **pile_a, t_p_swap **pile_b)
{
	if ((*pile_a)->next->number == 0 || (*pile_a)->next->next->number == 0)
	{	
		while ((*pile_a)->number != 0)
			ft_rotate(pile_a, "ra");
	}
	else
		while ((*pile_a)->number != 0)
			ft_reverse_rotate(pile_a, "rra");
	if (ft_pile_in_order(pile_a) == 1)
		return (1);
	ft_push(pile_a, pile_b, "pb");
	while ((*pile_a)->number != 1)
		ft_reverse_rotate(pile_a, "rra");
	if (ft_pile_in_order(pile_a) != 1)
	{
		ft_push(pile_a, pile_b, "pb");
		ft_count_is_3(pile_a);
		ft_push(pile_b, pile_a, "pa");
	}
	ft_push(pile_b, pile_a, "pa");
	return (1);
}

int	ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, t_struct *data, char **argv)
{
	int			size;
	t_p_swap	*temp;

	temp = *pile_a;
	size = data->count;
	if (data->count == 1 || ft_pile_in_order(pile_a) == 1)
		return (0);
	ft_set_number(pile_a, pile_b, data, size);
	if (data->count == 2)
	{
		if (temp->i > temp->next->i)
			ft_swap(pile_a, "sa");
		else
			return (0);
	}
	else if (data->count == 3)
		return (ft_count_is_3(pile_a));
	else if (data->count == 4)
		return (ft_count_is_4(pile_a, pile_b));
	else if (data->count == 5)
		return (ft_count_is_5(pile_a, pile_b));
	else if (data->count > 5)
		ft_order_bits(pile_a, pile_b, size);
	return (1);
}

int	push_swap(t_p_swap **pile_a, t_struct *data, int argc, char **argv)
{
	int			i;
	int			j;

	if (ft_check_error(pile_a, argc, argv) != 1)
		return (0);
	i = argc;
	j = -1;
	while (i-- > 1)
	{
		if (ft_check_space(i, j, argv) == 1)
			ft_long_arg(pile_a, data, argv, i);
		else if (ft_check_space(i, j, argv) == -1)
			return (ft_return_error());
		else
		{
			if (ft_atoli(argv[i]) < INT_MIN || ft_atoli(argv[i]) > INT_MAX)
				return (ft_return_error());
			ft_add_elem(pile_a, ft_atoi(argv[i]));
			data->count++;
		}
	}
	if (ft_check_if_double(pile_a) == 0)
		return (ft_return_error());
	return (1);
}
