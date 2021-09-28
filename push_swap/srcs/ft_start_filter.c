/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_filter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:17:51 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/27 17:17:53 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_start_filter(t_ps *ps)
{
	int	i[2];
	int	*order;
	int	lstep;

	lstep = 0;
	i[1] = 0;
	order = malloc(sizeof(int) * ps->qrt);
	if (!order)
		return (1);
	i[0] = -1;
	while (++i[0] < ps->qrt)
		ft_big_filter(ps, i[0], order, &lstep);
	i[0] = -1;
	while (++i[0] < ps->qrt)
	{
		if (ps->a[0] == order[i[1]])
		{
			i[1]++;
			ft_rab_ps(ps, 0);
		}
		else
			ft_pb_ps(ps);
	}
	free(order);
	return (0);
}

void	ft_four(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->qrt)
	{
		if (ps->a[0] == 4)
			ft_pb_ps(ps);
		ft_rab_ps(ps, 0);
	}
	ft_three_ps(ps);
	ft_pa_ps(ps);
	ft_rab_ps(ps, 0);
}

void	ft_last_five(t_ps *ps)
{
	ft_five(ps);
	ft_three_ps(ps);
	if (ps->b[0] == 1)
	{
		if (ps->comands[ps->cc - 1] == 1)
			ft_sab_ps(ps, 1);
		else if (ps->comands[ps->cc - 1] == 6)
			ft_rab_ps(ps, 1);
		else if (ps->comands[ps->cc - 1] == 9)
			ft_rrab_ps(ps, 1);
	}
	ft_pa_ps(ps);
	ft_pa_ps(ps);
}

void	ft_five_ffonft(t_ps *ps)
{
	ft_rrab_ps(ps, 0);
	ft_rrab_ps(ps, 0);
	ft_pb_ps(ps);
	ft_pb_ps(ps);
	ft_sab_ps(ps, 0);
	ft_sab_ps(ps, 1);
	ft_pa_ps(ps);
	ft_pa_ps(ps);
	ft_rrab_ps(ps, 0);
}

void	ft_three_ps(t_ps *ps)
{
	if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[2] > ps->a[0])
		return (ft_sab_ps(ps, 0));
	if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[2] < ps->a[0])
		return (ft_rrab_ps(ps, 0));
	if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[2] < ps->a[0])
		return (ft_rab_ps(ps, 0));
	if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2] && ps->a[2] < ps->a[0])
	{
		ft_sab_ps(ps, 0);
		return (ft_rrab_ps(ps, 0));
	}
	if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[2] > ps->a[0])
	{	
		ft_sab_ps(ps, 0);
		return (ft_rab_ps(ps, 0));
	}
	return ;
}
