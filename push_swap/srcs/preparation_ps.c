/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:23:48 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/17 20:23:49 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_maxmin_check(char **str, int qrt)
{
	int			i;
	long long	n;

	i = -1;
	while (++i < qrt)
	{
		n = ft_atoi(str[i]);
		if (n > 2147483647 || n < -2147483648)
			return (1);
	}
	return (0);
}

void	ft_free_str(char **str, int qrt)
{
	int	i;

	i = -1;
	while (++i < qrt)
	{
		free(str[i]);
	}
	free(str);
}

int	ft_work_while(int qty, char **str, int *a)
{
	int	i[3];

	i[0] = 1;
	while (i[0] <= qty)
	{
		i[2] = 0;
		i[1] = 1;
		while (i[1] < qty)
		{
			while (!str[i[2]])
				i[2]++;
			while (!str[i[1]] || i[1] == i[2])
				i[1]++;
			if (i[1] < qty)
				i[2] = ft_ascend(str[i[2]], str[i[1]], i[2], i[1]);
			if (i[2] == -1)
				return (1);
			i[1]++;
		}
		free(str[i[2]]);
		str[i[2]] = NULL;
		a[i[2]] = i[0];
		i[0]++;
	}
	return (0);
}

int	ft_ascend_and_input(char **str, int qty, int *a)
{
	int	i;

	i = 0;
	while (i < qty)
		if (ft_check_input(str[i++]))
			return (1);
	if (ft_maxmin_check(str, qty))
		return (1);
	if (ft_work_while(qty, str, a))
		return (1);
	ft_free_str(str, qty);
	return (0);
}
