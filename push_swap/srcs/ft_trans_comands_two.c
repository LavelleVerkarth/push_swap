/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_comands_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:37:18 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/27 19:37:19 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_treatmeant_six(int *ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 6)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 7 && n == 1)
		{
			ps->comands[posn] = 8;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 6 && ps->comands[i] != 7 && ps->comands[i] != 8)
			n = 0;
	}
}

void	ft_treatmeant_seven(int	*ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 7)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 6 && n == 1)
		{
			ps->comands[posn] = 8;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 6 && ps->comands[i] != 7 && ps->comands[i] != 8)
			n = 0;
	}
}

void	ft_treatmeant_nine(int	*ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 9)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 10 && n == 1)
		{
			ps->comands[posn] = 11;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 9 && ps->comands[i] != 10 && ps->comands[i] != 11)
			n = 0;
	}
}

void	ft_treatmeant_ten(int	*ret, t_ps *ps)
{
	int	i;
	int	n;
	int	posn;

	n = 0;
	i = -1;
	posn = 0;
	while (++i < ps->cc)
	{
		if (ps->comands[i] == 10)
		{
			posn = i;
			n = 1;
		}
		else if (ps->comands[i] == 9 && n == 1)
		{
			ps->comands[posn] = 11;
			ps->comands[i] = 0;
			n = 0;
			(*ret)++;
		}
		else if (ps->comands[i] != 0 && ps->comands[i]
			!= 9 && ps->comands[i] != 10 && ps->comands[i] != 11)
			n = 0;
	}
}
