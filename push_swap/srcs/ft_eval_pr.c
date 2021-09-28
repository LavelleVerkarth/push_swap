/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:52:27 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/18 11:52:29 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_evaluate_position(int *a, int qrt)
{
	int	i;

	i = 0;
	while (++i < qrt)
	{
		if (a[i] - a[i - 1] != 1)
			return (0);
	}
	return (1);
}

t_way	*ft_create_way(void)
{
	t_way	*way;

	way = malloc(sizeof(t_way));
	if (!way)
		return (NULL);
	way->step = 5000;
	way->ina = 0;
	way->inb = 0;
	way->size = 0;
	return (way);
}

int	ft_count_size(t_ps *ps, int *a)
{
	int	i;

	i = -1;
	while (++i < ps->qrt)
		if (a[i] == 0)
			return (i);
	return (ps->qrt);
}

int	ft_better_way(t_ps *ps, int b)
{
	int	i;
	int	last;
	int	min;

	last = ps->qrt + 1;
	min = 0;
	i = -1;
	while (++i < ps->qrt)
	{
		if (ps->a[i] < ps->a[min] && ps->a[i] != 0)
			min = i;
		if (ps->a[i] > b && ps->a[i] < last)
			last = ps->a[i];
	}
	if (last == ps->qrt + 1)
		return (min);
	i = -1;
	while (++i < ps->qrt)
		if (ps->a[i] == last)
			return (i);
	return (-1);
}
