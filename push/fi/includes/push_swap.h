/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:10:55 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 20:28:32 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_push
{
	int				*a;
	int				*b;
	int				**ab;
	int				k;
	int				k_a;
	int				k_b;
	int				i;
	int				n;
}					t_push;

typedef struct		s_parse
{
	int				v;
	struct s_parse	*next;
}					t_parse;

int					theend(t_push *p);
int					maxs(int *a, int k, int n);
int					imas(int **a, int k, int n);
int					fun_pa(t_push *p);
int					fun_ra(t_push *p, int f);
int					fun_sa(t_push *p);
int					fun_rra(t_push *p, int f);
int					predvar(t_push *p);
int					predvartwo(t_push *p);
int					predvarx(t_push *p);
int					predvartwox(t_push *p);
int					fun_rrb(t_push *p, int f);
int					fun_rb(t_push *p, int f);
int					fun_pb(t_push *p);
int					min_pair(int n, t_push *p);
int					max_pair(int n, t_push *p);
int					mas_pair(t_push *p);
int					alg(t_push *p);
int					fun_sb(t_push *p);
int					mesto(int *m, int n, int k, int a);
int					max_mesto(t_push *p);
int					max_m(int *a, int k);
int					fun_rr(t_push *p);
int					check(int *s, int k);
void				alignment_a(t_push *p);
int					check_replay(int *m, int k);
int					fun_rr(t_push *p);
int					fun_rrr(t_push *p);
void				mesto_in(int l[5]);
void				mesto1(int l[5], int *m);
void				init(t_parse *parse, t_push *p, int k);
void				free_memory(t_push *p, int f);
int					parse_main(char *s, t_parse *p);
int					ctoi(char *s, int i, t_parse *p, int f);
void				add_elem_parse(t_parse *p, int data);
void				init_mv(int v[4]);
int					parse(int argc, char **argv, t_push *ps);
int					distrib(char *s, int q, t_push *p);
int					distrib2(char *s, int q, t_push *p);
int					distrib3(char *s, int q, t_push *p);
int					fun_cpa(t_push *p);
int					fun_cra(t_push *p);
int					fun_csa(t_push *p);
int					fun_crra(t_push *p);
int					fun_crrb(t_push *p);
int					fun_crb(t_push *p);
int					fun_cpb(t_push *p);
int					fun_csb(t_push *p);
void				free_memorys(t_push *p, char *s);
void				print(int f, t_push *p, char *s);
void				printik(t_push *p, char *s);
t_parse				*remove_all(t_parse *head);
int					ff(t_parse *p);
void				fff(t_push *p);

#endif
