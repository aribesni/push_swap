/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:24:05 by aribesni          #+#    #+#             */
/*   Updated: 2021/08/24 09:24:07 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_fill_str(char **argv, int i, int *j)
{
	int			k;
	char		*str;

	k = *j;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(argv[i]) + 1)))
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
