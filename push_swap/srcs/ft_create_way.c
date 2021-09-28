/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:22:59 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/19 09:23:12 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab_ps(t_ps *ps, int p)
{
	int	tmp;

	if (p == 0)
	{
		tmp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = tmp;
		ps->comands[ps->cc] = 1;
		ps->cc++;
		return ;
	}
	tmp = ps->b[0];
	ps->b[0] = ps->b[1];
	ps->b[1] = tmp;
	ps->comands[ps->cc] = 2;
	ps->cc++;
}

void	ft_pb_ps(t_ps *ps)
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
	ps->comands[ps->cc] = 5;
	ps->cc++;
}

void	ft_pa_ps(t_ps *ps)
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
	ps->comands[ps->cc] = 4;
	ps->cc++;
}

void	ft_rab_ps(t_ps *ps, int p)
{
	int	i;
	int	tmp;

	if (p == 0)
	{
		tmp = ps->a[0];
		i = 0;
		while (++i < ps->qrt && ps->a[i] != 0)
			ps->a[i - 1] = ps->a[i];
		ps->a[i - 1] = tmp;
		ps->comands[ps->cc] = 6;
		ps->cc++;
		return ;
	}
	tmp = ps->b[0];
	i = 0;
	while (++i < ps->qrt && ps->b[i] != 0)
		ps->b[i - 1] = ps->b[i];
	ps->b[i - 1] = tmp;
	ps->comands[ps->cc] = 7;
	ps->cc++;
}

void	ft_rrab_ps(t_ps *ps, int p)
{
	int	i;
	int	tmp;

	if (p == 0)
	{
		i = 0;
		while (ps->a[i] != 0 && i < ps->qrt)
			i++;
		tmp = ps->a[i - 1];
		while (--i > 0)
			ps->a[i] = ps->a[i - 1];
		ps->a[0] = tmp;
		ps->comands[ps->cc] = 9;
		ps->cc++;
		return ;
	}
	i = 0;
	while (ps->b[i] != 0 && i < ps->qrt)
		i++;
	tmp = ps->b[i - 1];
	while (--i > 0)
		ps->b[i] = ps->b[i - 1];
	ps->b[0] = tmp;
	ps->comands[ps->cc] = 10;
	ps->cc++;
}
