/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:33:19 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/23 17:33:21 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_step_another(int a, int b, int step, t_way *way)
{
	if (a < 0 && b < 0)
	{
		if (a < b)
			step = a * -1;
		else
			step = b * -1;
	}
	if (a > 0 && b > 0)
	{
		if (a > b)
			step = a;
		else
			step = b;
	}
	if (step < way->step)
	{
		way->step = step;
		way->ina = a;
		way->inb = b;
	}
}

void	ft_count_step(t_ps *ps, int pos, t_way *way)
{
	int	step;
	int	b;
	int	posa;
	int	a;

	b = pos;
	if (pos <= way->size / 2)
		step = pos;
	else
	{
		step = way->size - pos;
		b = -step;
	}
	posa = ft_better_way(ps, ps->b[pos]);
	a = posa;
	if (posa <= ft_count_size(ps, ps->a) / 2)
		step += posa;
	else
	{
		step += ft_count_size(ps, ps->a) - posa;
		a = (ft_count_size(ps, ps->a) - posa) * -1;
	}
	ft_count_step_another(a, b, step, way);
}

void	ft_moved_ps(t_ps *ps, t_way *way)
{
	while (way->inb > 0)
	{
		ft_rab_ps(ps, 1);
		way->inb--;
	}
	while (way->inb < 0)
	{
		ft_rrab_ps(ps, 1);
		way->inb++;
	}
	while (way->ina > 0)
	{
		ft_rab_ps(ps, 0);
		way->ina--;
	}
	while (way->ina < 0)
	{
		ft_rrab_ps(ps, 0);
		way->ina++;
	}
	ft_pa_ps(ps);
}

int	ft_brows_b(t_ps *ps)
{
	int		i;
	t_way	*way;

	way = ft_create_way();
	if (way == NULL)
		return (1);
	way->size = ft_count_size(ps, ps->b);
	i = -1;
	while (++i < way->size)
	{
		ft_count_step(ps, i, way);
	}
	ft_moved_ps(ps, way);
	free(way);
	return (0);
}

int	ft_another_ps(t_ps *ps)
{
	int	i;
	int	f;

	if (ft_start_filter(ps))
		return (1);
	while (ps->b[0] != 0)
		if (ft_brows_b(ps))
			return (1);
	i = -1;
	while (++i < ps->qrt)
		if (ps->a[i] == 1)
			f = i;
	if (f <= ps->qrt / 2)
		while (ps->a[0] != 1)
			ft_rab_ps(ps, 0);
	else
		while (ps->a[0] != 1)
			ft_rrab_ps(ps, 0);
	return (0);
}
