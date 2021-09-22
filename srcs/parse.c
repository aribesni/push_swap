/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:07:42 by aribesni          #+#    #+#             */
/*   Updated: 2021/08/25 09:50:43 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(t_p_swap **pile_a, int argc, char **argv)
{
	int			i;

	i = argc;
	if (argc == 1)
		return (0);
	while (i-- > 1)
	{
		if (ft_strlen(argv[i]) == 0)
			return (ft_return_error(pile_a));
	}
	return (1);
}

int	ft_check_space(int i, int j, char **argv)
{
	int			count;

	count = 0;
	while (++j < ft_strlen(argv[i]))
	{
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{	
			if (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
				j++;
			else
				return (-1);
		}
		if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' ' &&
			argv[i][j] != '+' && argv[i][j] != '-')
			return (-1);
		if (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			count++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
		}
	}
	if (count > 1)
		return (1);
	return (0);
}

int	ft_check_if_empty(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_double(t_p_swap **pile_a)
{
	t_p_swap	*temp_1;
	t_p_swap	*temp_2;

	temp_1 = *pile_a;
	while (temp_1->next)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->i == temp_2->i)
				return (0);
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
	return (1);
}

int	ft_long_arg(t_p_swap **pile_a, t_struct *data, char **argv, int i)
{
	int			j;
	int			k;
	char		*str;

	j = ft_strlen(argv[i]) - 1;
	while (j > 0)
	{
		k = j;
		str = ft_fill_str(argv, i, &j, k);
		if (ft_check_if_empty(str) == 1)
			break ;
		if (ft_atoli(str) < INT_MIN || ft_atoli(str) > INT_MAX)
			return (ft_return_error(pile_a));
		ft_add_elem(pile_a, ft_atoi(str));
		data->count++;
		free(str);
	}
	return (1);
}
