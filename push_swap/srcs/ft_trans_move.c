/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:24:04 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/28 16:24:05 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab_cps(t_ps *ps, int p)
{
	int	tmp;

	if (p == 1 || p == 3)
	{
		tmp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = tmp;
	}
	if (p == 2 || p == 3)
	{
		tmp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = tmp;
	}
}

void	ft_pb_cps(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->b[i] != 0)
		i++;
	while (i > 0)
	{
		ps->b[i] = ps->b[i - 1];
		i--;
	}
	ps->b[0] = ps->a[0];
	i = 0;
	while (++i < ps->qrt)
		ps->a[i - 1] = ps->a[i];
	ps->a[i - 1] = 0;
}

void	ft_pa_cps(t_ps *ps)
{
	int	i;

	i = 0;
	while (ps->a[i] != 0)
		i++;
	while (i > 0)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[0] = ps->b[0];
	i = 0;
	while (++i < ps->qrt)
		ps->b[i - 1] = ps->b[i];
	ps->b[i - 1] = 0;
}

void	ft_rab_cps(t_ps *ps, int p)
{
	int	i;
	int	tmp;

	if (p == 6 || p == 8)
	{
		tmp = ps->a[0];
		i = 0;
		while (++i < ps->qrt && ps->a[i] != 0)
			ps->a[i - 1] = ps->a[i];
		ps->a[i - 1] = tmp;
	}
	if (p == 7 || p == 8)
	{
		tmp = ps->b[0];
		i = 0;
		while (++i < ps->qrt && ps->b[i] != 0)
			ps->b[i - 1] = ps->b[i];
		ps->b[i - 1] = tmp;
	}
}

void	ft_rrab_cps(t_ps *ps, int p)
{
	int	i;
	int	tmp;

	if (p == 9)
	{
		i = 0;
		while (ps->a[i] != 0 && i < ps->qrt)
			i++;
		tmp = ps->a[i - 1];
		while (--i > 0)
			ps->a[i] = ps->a[i - 1];
		ps->a[0] = tmp;
	}
	if (p == 10 || p == 11)
	{
		i = 0;
		while (ps->b[i] != 0 && i < ps->qrt)
			i++;
		tmp = ps->b[i - 1];
		while (--i > 0)
			ps->b[i] = ps->b[i - 1];
		ps->b[0] = tmp;
	}
}
