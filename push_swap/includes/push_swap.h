/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:27:23 by lverkart          #+#    #+#             */
/*   Updated: 2021/05/17 20:27:26 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	qrt;
	int	*comands;
	int	cc;
}				t_ps;

typedef struct s_way
{
	int	step;
	int	ina;
	int	inb;
	int	size;
}				t_way;

void	ft_trans_comands(t_ps *ps);
void	ft_sab_ps(t_ps *ps, int p);
void	ft_pa_ps(t_ps *ps);
void	ft_pb_ps(t_ps *ps);
void	ft_rab_ps(t_ps *ps, int p);
void	ft_rrab_ps(t_ps *ps, int p);
int		ft_ascend_and_input(char **str, int qty, int *a);
int		ft_evaluate_position(int *a, int qrt);
char	**ft_strddup(char **str, int qrt);
void	ft_five_ps(t_ps *ps);
int		ft_another_ps(t_ps *ps);
int		ft_start_filter(t_ps *ps);
int		ft_treatmeant_comands(t_ps *ps);
t_way	*ft_create_way(void);
int		ft_count_size(t_ps *ps, int *a);
int		ft_better_way(t_ps *ps, int b);
void	ft_big_filter(t_ps *ps, int last, int *order, int *lstep);
void	ft_four(t_ps *ps);
void	ft_last_five(t_ps *ps);
void	ft_five_ffonft(t_ps *ps);
void	ft_three_ps(t_ps *ps);
void	ft_five(t_ps *ps);
void	ft_treatmeant_one(int	*ret, t_ps *ps);
void	ft_treatmeant_two(int	*ret, t_ps *ps);
int		ft_treatmeant_comands(t_ps *ps);
void	ft_comands_number(t_ps *ps, int i);
void	ft_trans_comands(t_ps *ps);
void	ft_treatmeant_six(int *ret, t_ps *ps);
void	ft_treatmeant_seven(int	*ret, t_ps *ps);
void	ft_treatmeant_nine(int	*ret, t_ps *ps);
void	ft_treatmeant_ten(int	*ret, t_ps *ps);
int		ft_ascend_part(char *s1, char *s2, int ss1, int ss2);
int		ft_ascend_part_two(char *s1, char *s2, int ss1, int ss2);
int		ft_ascend(char *s1, char *s2, int ss1, int ss2);
int		ft_check_input(char *str);
t_ps	*ft_creat_cps(int *a, int *b, int qrt);
int		ft_free_cps(int *a, int *b, char **argv, int qrt);
int		ft_free_for_cps(t_ps *ps);
void	ft_sab_cps(t_ps *ps, int p);
void	ft_pb_cps(t_ps *ps);
void	ft_pa_cps(t_ps *ps);
void	ft_rab_cps(t_ps *ps, int p);
void	ft_rrab_cps(t_ps *ps, int p);

#endif
