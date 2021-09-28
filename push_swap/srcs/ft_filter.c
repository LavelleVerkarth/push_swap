/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:49:41 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/25 18:49:43 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_filter_part(t_ps *ps, int llast, int *step)
{
	int	i;

	i = llast;
	while (++i < ps->qrt)
	{
		if (ps->a[i] - ps->a[llast] == 1)
		{
			llast = i;
			(*step)++;
		}
	}
}

void	ft_filter_part_two(t_ps *ps, int llast, int *order, int *n)
{
	int	i;

	i = llast;
	while (++i < ps->qrt)
	{
		if (ps->a[i] - ps->a[llast] == 1)
		{
			llast = i;
			order[(*n)++] = ps->a[i];
		}
	}
}

void	ft_filter_part_three(t_ps *ps, int llast, int *step)
{
	int	i;

	i = llast;
	while (++i < ps->qrt)
	{
		if (ps->a[i] > ps->a[llast])
		{
			llast = i;
			(*step)++;
		}
	}
}

void	ft_filter_part_four(t_ps *ps, int *llast, int *order, int *n)
{
	int	i;

	i = *llast;
	while (++i < ps->qrt)
	{
		if (ps->a[i] > ps->a[*llast])
		{
			*llast = i;
			order[(*n)++] = ps->a[i];
		}
	}
}

void	ft_big_filter(t_ps *ps, int last, int *order, int *lstep)
{
	int	step;
	int	n;
	int	llast;

	step = 0;
	n = 0;
	llast = last;
	ft_filter_part(ps, llast, &step);
	if (step > *lstep)
	{
		*lstep = step;
		order[n++] = ps->a[last];
		ft_filter_part_two(ps, llast, order, &n);
	}
	step = 0;
	ft_filter_part_three(ps, llast, &step);
	n = 0;
	if (step > *lstep)
	{
		*lstep = step;
		order[n++] = ps->a[llast];
		ft_filter_part_four(ps, &llast, order, &n);
	}
}
