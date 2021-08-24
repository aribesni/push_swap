/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:56:12 by aribesni          #+#    #+#             */
/*   Updated: 2021/07/22 19:00:20 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min(t_p_swap **pile_a, t_p_swap **pile_b, int max, int *size)
{
	int			min;
	t_p_swap	*temp_1;
	t_p_swap	*temp_2;

	temp_1 = *pile_a;
	min = temp_1->i;
	while (temp_1->next)
	{
		temp_1 = temp_1->next;
		if (min > temp_1->i)
			min = temp_1->i;
	}
	temp_1 = *pile_a;
	temp_2 = temp_1->next;
	if (temp_1->i == min)
	{
		ft_push(pile_a, pile_b, "pb");
		*size = *size - 1;
	}
	if (temp_1->i != max && temp_2->i != max && temp_1->i > temp_2->i)
		ft_swap(pile_a, "sa");
}

int	ft_order(t_p_swap **pile_a, t_p_swap **pile_b, int max, int *size)
{
	int			j;
	int			min;
	t_p_swap	*temp_1;
	t_p_swap	*temp_2;

	j = 0;
	while (++j && ft_pile_in_order(pile_a) != 1)
	{
		ft_min(pile_a, pile_b, max, size);
		if (ft_pile_in_order(pile_a) == 1)
			return (1);
		ft_reverse_rotate(pile_a, "rra");
	}
	return (1);
}

void	ft_set_max(t_p_swap **pile_a, t_p_swap **pile_b, int *size)
{
	int			max;
	t_p_swap	*temp;

	temp = *pile_a;
	max = temp->i;
	while (temp->next)
	{
		temp = temp->next;
		if (max < temp->i)
			max = temp->i;
	}
	ft_order(pile_a, pile_b, max, size);
}

int	ft_exec(t_p_swap **pile_a, t_p_swap **pile_b, t_struct *data, char **argv)
{
	int			i;
	int			size;
	t_p_swap	*temp;

	i = 1;
	temp = *pile_a;
	size = data->count;
	if (data->count == 1 || ft_pile_in_order(pile_a) == 1)
		return (0);
	if (data->count == 2)
	{
		if (temp->i > temp->next->i)
			ft_swap(pile_a, "sa");
		else
			return (0);
	}
	else if (data->count > 2)
	{
		ft_set_max(pile_a, pile_b, &size);
		if (ft_full_pile_in_order(pile_a, data->count) == 1)
			return (1);
		while (i++ < data->count - size + 1)
			ft_push(pile_b, pile_a, "pa");
	}
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