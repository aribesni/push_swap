/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:24:05 by aribesni          #+#    #+#             */
/*   Updated: 2021/09/21 10:26:55 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_return_max(t_p_swap **pile_a)
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
	return (max);
}

int	ft_return_min(t_p_swap **pile_a)
{
	int			min;
	t_p_swap	*temp;

	temp = *pile_a;
	min = temp->i;
	while (temp->next)
	{
		temp = temp->next;
		if (min > temp->i)
			min = temp->i;
	}
	return (min);
}

int	ft_return_mid(t_p_swap **pile_a, int min, int max)
{
	int			mid;
	t_p_swap	*temp;

	temp = *pile_a;
	mid = temp->i;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->i != min && temp->i != max)
			mid = temp->i;
	}
	return (mid);
}

char	*ft_fill_str(char **argv, int i, int *j, int k)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(argv[i]) + 1);
	if (!str)
		return (NULL);
	str[k + 1] = '\0';
	while (argv[i][*j] == ' ')
		*j -= 1;
	while (argv[i][*j] >= '0' && argv[i][*j] <= '9')
	{
		str[k--] = argv[i][*j];
		*j -= 1;
	}
	if (argv[i][*j] == '-' || argv[i][*j] == '+')
	{
		if (argv[i][*j] == '-')
		{
			str[k] = argv[i][*j];
			k--;
		}
		*j -= 1;
	}
	while (k >= 0)
		str[k--] = ' ';
	return (str);
}

void	ft_order_bits(t_p_swap **pile_a, t_p_swap **pile_b, int size)
{
	int			i;
	int			j;
	int			max_bits;

	i = 0;
	j = 0;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*pile_a)->number >> i) & 1) == 1)
				ft_rotate(pile_a, "ra");
			else
				ft_push(pile_a, pile_b, "pb");
			j++;
		}
		while ((*pile_b)->next)
			ft_push(pile_b, pile_a, "pa");
		i++;
	}
}
