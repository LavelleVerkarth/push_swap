/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utilus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:32:23 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/28 17:32:25 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_creat_cps(int *a, int *b, int qrt)
{
	t_ps	*ret;

	ret = malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->comands = malloc(sizeof(int) * 10000);
	if (!(ret->comands))
	{
		free(ret);
		return (NULL);
	}
	ret->a = a;
	ret->b = b;
	ret->qrt = qrt;
	ret->cc = 0;
	return (ret);
}

int	ft_free_cps(int *a, int *b, char **argv, int qrt)
{
	int	i;

	free(a);
	free(b);
	i = -1;
	while (++i < qrt)
		free(argv[i]);
	free(argv);
	write(1, "Error\n", 6);
	return (0);
}

int	ft_free_for_cps(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps->comands);
	free(ps);
	return (0);
}
