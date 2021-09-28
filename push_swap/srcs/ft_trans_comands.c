/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_comands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:29:42 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/27 19:29:45 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_treatmeant_one(int	*ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 1)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 2 && n == 1)
		{
			ps->comands[posn] = 3;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 1 && ps->comands[i] != 2 && ps->comands[i] != 3)
			n = 0;
	}
}

void	ft_treatmeant_two(int *ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 2)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 1 && n == 1)
		{
			ps->comands[posn] = 3;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 1 && ps->comands[i] != 2 && ps->comands[i] != 3)
			n = 0;
	}
}

int	ft_treatmeant_comands(t_ps *ps)
{
	int	ret;

	ret = 0;
	ft_treatmeant_six(&ret, ps);
	ft_treatmeant_seven(&ret, ps);
	ft_treatmeant_nine(&ret, ps);
	ft_treatmeant_ten(&ret, ps);
	ft_treatmeant_one(&ret, ps);
	ft_treatmeant_two(&ret, ps);
	return (ret);
}

void	ft_comands_number(t_ps *ps, int i)
{
	if (ps->comands[i] == 1)
		ft_putstr_fd("sa\n", 1);
	else if (ps->comands[i] == 2)
		ft_putstr_fd("sb\n", 1);
	else if (ps->comands[i] == 3)
		ft_putstr_fd("ss\n", 1);
	else if (ps->comands[i] == 4)
		ft_putstr_fd("pa\n", 1);
	else if (ps->comands[i] == 5)
		ft_putstr_fd("pb\n", 1);
	else if (ps->comands[i] == 6)
		ft_putstr_fd("ra\n", 1);
	else if (ps->comands[i] == 7)
		ft_putstr_fd("rb\n", 1);
	else if (ps->comands[i] == 8)
		ft_putstr_fd("rr\n", 1);
	else if (ps->comands[i] == 9)
		ft_putstr_fd("rra\n", 1);
	else if (ps->comands[i] == 10)
		ft_putstr_fd("rrb\n", 1);
	else if (ps->comands[i] == 11)
		ft_putstr_fd("rrr\n", 1);
}

void	ft_trans_comands(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->cc)
		ft_comands_number(ps, i);
}
