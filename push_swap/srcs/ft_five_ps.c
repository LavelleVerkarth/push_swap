/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:12:39 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/19 20:12:42 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_five_par(t_ps *ps, int ver)
{
	int	i;
	int	dop;

	dop = 2;
	i = -1;
	while (++i < ps->qrt && dop != 0 )
	{
		if (ps->a[0] == 1 || ps->a[0] == 2)
		{
			dop--;
			ft_pb_ps(ps);
		}
		else if (ver == 0)
			ft_rrab_ps(ps, 0);
		else if (ver == 1)
			ft_rab_ps(ps, 0);
	}
}

void	ft_five_dop_com(t_ps *ps, int ver)
{
	if (ver == 0)
		ft_pb_ps(ps);
	ft_rrab_ps(ps, 0);
	ft_pb_ps(ps);
	if (ver == 1)
	{
		ft_rab_ps(ps, 0);
		ft_pb_ps(ps);
	}
}

void	ft_five_parse(t_ps *ps, int *n1, int *n2)
{
	int	i;

	i = -1;
	while (++i < ps->qrt)
	{
		if (ps->a[i] == 1)
			*n1 = i;
		if (ps->a[i] == 2)
			*n2 = i;
	}
}

void	ft_five(t_ps *ps)
{
	int	n1;
	int	n2;
	int	dd;

	n1 = 0;
	n2 = 0;
	dd = 0;
	ft_five_parse(ps, &n1, &n2);
	if ((n1 == 2 || n1 == 3) && (n2 == 2 || n2 == 3))
		dd = 1;
	if ((n1 == 2 || n1 == 4) && (n2 == 2 || n2 == 4))
		dd = 1;
	if (ps->a[0] == 3 && ps->a[1] == 5 && ps->a[3] == 4)
		dd = 0;
	if (n1 >= 2 && n2 >= 2 && dd == 0)
		ft_five_par(ps, 0);
	else if ((n1 == 0 && n2 == 4) || (n2 == 0 && n1 == 4))
		ft_five_dop_com(ps, 0);
	else if ((n1 == 1 && n2 == 4) || (n2 == 1 && n1 == 4))
		ft_five_dop_com(ps, 1);
	else
		ft_five_par(ps, 1);
}

void	ft_five_ps(t_ps *ps)
{
	if (ps->qrt == 2)
		return (ft_putstr_fd("sa\n", 1));
	if (ps->qrt == 3)
		return (ft_three_ps(ps));
	if (ps->qrt == 4)
		return (ft_four(ps));
	if (ps->a[0] == 5 && ps->a[1] == 4 && ps->a[2] == 2 && ps->a[3] == 3)
	{
		ft_pb_ps(ps);
		ft_pb_ps(ps);
		ft_three_ps(ps);
		ft_pa_ps(ps);
		ft_rab_ps(ps, 0);
		ft_pa_ps(ps);
		ft_rab_ps(ps, 0);
	}
	else if (ps->a[0] == 5 && ps->a[1] == 4 && ps->a[2] == 1 && ps->a[3] == 3)
		ft_five_ffonft(ps);
	else
		ft_last_five(ps);
}
