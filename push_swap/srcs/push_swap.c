/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:59:54 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/16 17:59:59 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*ft_creat_ps(int *a, int *b, int qrt)
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

int	ft_free_ps(int *a, int *b, char **argv, int qrt)
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

int	ft_free_for_ps(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps->comands);
	free(ps);
	return (0);
}

int	ft_start_ps(char **argv, int qrt, int *a, int *b)
{
	t_ps	*ps;

	if (ft_ascend_and_input(argv, qrt, a))
		return (write(1, "Error\n", 6) - 6);
	ps = ft_creat_ps(a, b, qrt);
	if (!ps)
		return (ft_free_ps(a, b, argv, qrt));
	if (ft_evaluate_position(a, qrt) || qrt == 1)
		return (ft_free_for_ps(ps));
	if (qrt <= 5)
	{
		ft_five_ps(ps);
		while (ft_treatmeant_comands(ps) > 0)
			;
		ft_trans_comands(ps);
		return (ft_free_for_ps(ps));
	}
	if (ft_another_ps(ps))
		return (1);
	while (ft_treatmeant_comands(ps) > 0)
		;
	ft_trans_comands(ps);
	return (ft_free_for_ps(ps));
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		qrt;

	if (argc == 1)
		return (write(1, "Еnter integer digits!\n", 23) - 23);
	qrt = argc - 1;
	argv++;
	if (argc == 2)
	{
		argv = ft_split(argv[0], ' ');
		if (!argv)
			return (write(1, "Error\n", 6) - 6);
		qrt = 0;
		while (argv[qrt] != NULL)
			qrt++;
	}
	else
		argv = ft_strddup(argv, qrt);
	a = malloc(sizeof(int) * qrt);
	b = ft_calloc(qrt, sizeof(int));
	if (!a || !b || !argv)
		return (ft_free_ps(a, b, argv, qrt));
	return (ft_start_ps(argv, qrt, a, b));
}		
