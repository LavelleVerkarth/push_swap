/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:57:08 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/28 14:57:10 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_comands(char *l, t_ps *ps)
{
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\0')
		ps->comands[ps->cc] = 1;
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\0')
		ps->comands[ps->cc] = 2;
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\0')
		ps->comands[ps->cc] = 3;
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\0')
		ps->comands[ps->cc] = 4;
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\0')
		ps->comands[ps->cc] = 5;
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\0')
		ps->comands[ps->cc] = 6;
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\0')
		ps->comands[ps->cc] = 7;
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\0')
		ps->comands[ps->cc] = 8;
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\0')
		ps->comands[ps->cc] = 9;
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\0')
		ps->comands[ps->cc] = 10;
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\0')
		ps->comands[ps->cc] = 11;
	else
		return (0);
	return (++(ps->cc));
}

int	get_next_line(char **line)
{
	char	buff;
	int		i;
	char	*tmp;

	i = 0;
	if (!line)
		return (-1);
	tmp = malloc(sizeof(char) * 100);
	while (read(0, &buff, 1) > 0)
	{
		tmp[i] = buff;
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			*line = tmp;
			return (1);
		}
		i++;
	}
	tmp[i] = '\0';
	*line = tmp;
	return (0);
}

void	ft_trans_move(t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < ps->cc)
	{
		if (ps->comands[i] <= 3)
			ft_sab_cps(ps, ps->comands[i]);
		else if (ps->comands[i] == 4)
			ft_pa_cps(ps);
		else if (ps->comands[i] == 5)
			ft_pb_cps(ps);
		else if (ps->comands[i] <= 8)
			ft_rab_cps(ps, ps->comands[i]);
		else if (ps->comands[i] <= 11)
			ft_rrab_cps(ps, ps->comands[i]);
	}
}

int	ft_check_start_cps(char **argv, int qrt, int *a, int *b)
{
	t_ps	*ps;
	char	*line;

	if (ft_ascend_and_input(argv, qrt, a))
		return (write(1, "Error\n", 6) - 6);
	ps = ft_creat_cps(a, b, qrt);
	if (!ps)
		return (ft_free_cps(a, b, argv, qrt));
	while (get_next_line(&line))
	{
		if (ft_check_comands(line, ps) == 0)
		{
			ft_free_for_cps(ps);
			free(line);
			return (write(1, "Error\n", 6) - 6);
		}
		free(line);
	}
	ft_trans_move(ps);
	if (ft_evaluate_position(ps->a, ps->qrt) || ps->qrt == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_free_for_cps(ps));
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
		return (ft_free_cps(a, b, argv, qrt));
	return (ft_check_start_cps(argv, qrt, a, b));
}
