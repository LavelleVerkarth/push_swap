/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_problem_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:12:01 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/27 20:12:02 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_strddup(char **str, int qrt)
{
	char	**ret;
	int		i;

	i = -1;
	ret = malloc(sizeof(char *) * (qrt + 1));
	if (!ret)
		return (NULL);
	ret[qrt] = NULL;
	while (++i < qrt)
	{
		ret[i] = ft_strdup(str[i]);
		if (ret[i] == NULL)
		{
			while (--i >= 0)
				free(ret[i]);
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

int	ft_check_input(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == 0 && str[i + 1] == '\0')
		return (1);
	while (str[++i])
	{
		if (!(ft_isdigit(str[i])))
			return (1);
	}
	return (0);
}

int	ft_ascend_part(char *s1, char *s2, int ss1, int ss2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ss1);
	else if (ft_strlen(s1) < ft_strlen(s2))
		return (ss2);
	while (s1[i] && s2[i])
	{
		if (s1[i] < s2[i])
			return (ss1);
		else if (s1[i] > s2[i])
			return (ss2);
		i++;
	}
	return (-1);
}

int	ft_ascend_part_two(char *s1, char *s2, int ss1, int ss2)
{
	int	i;
	int	n;
	int	j;

	n = 0;
	j = 0;
	i = 0;
	if (s1[0] == '+')
		n =1;
	if (s2[0] == '+')
		j = 1;
	if (ft_strlen(s1) - n > ft_strlen(s2) - j)
		return (ss2);
	else if (ft_strlen(s1) - n < ft_strlen(s2) - j)
		return (ss1);
	while (s1[i + n] && s2[i + j])
	{
		if (s1[i + n] > s2[i + j])
			return (ss2);
		else if (s1[i + n] < s2[i + j])
			return (ss1);
		i++;
	}
	return (-1);
}

int	ft_ascend(char *s1, char *s2, int ss1, int ss2)
{
	int	i;

	i = 0;
	if (s1[0] == '-' && s2[0] != '-')
		return (ss1);
	else if (s1[0] != '-' && s2[0] == '-')
		return (ss2);
	else if (s1[0] == '-' && s2[0] == '-')
		return (ft_ascend_part(s1, s2, ss1, ss2));
	else
		return (ft_ascend_part_two(s1, s2, ss1, ss2));
	return (-1);
}
