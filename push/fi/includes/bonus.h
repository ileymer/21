/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:54:55 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/27 15:55:45 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

typedef struct		s_visual
{
	int				*a;
	int				*b;
	int				mr[1000];
	int				**pr;
	int				i[1];
	int				k;
	int				k_a;
	int				k_b;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_visual;

void				init_m(long m[3]);
int					mas_pair(t_visual *p);
void				mas_preobr(int **pr, int *a, int n);
int					distrib(char *s, int q, int a[1000], int i);
int					distrib2(char *s, int q, int a[1000], int i);
int					distrib3(char *s, int q, int a[1000], int i);
int					ctoi(char *s, t_visual *p, int j);
int					check(int *s, int k);
int					*m4(int x, int y, int lx, int ly);
int					pixel_print(t_visual *s, int *m, int color);
void				visual (t_visual *p);
int					fun_vpa(t_visual *p);
int					fun_vra(t_visual *p);
int					fun_vsa(t_visual *p);
int					fun_vrra(t_visual *p);
int					fun_vrrb(t_visual *p);
int					fun_vrb(t_visual *p);
int					fun_vpb(t_visual *p);
int					fun_vsb(t_visual *p);
int					vivviz(int key, t_visual *p);
void				viviz_b(t_visual *p, int b, int r, int a);
void				viviz_a(t_visual *p, int b, int r, int a);
void				free_mem(t_visual *p);
void				run(t_visual *p);
void				run2(t_visual *p);
void				run3(t_visual *p);

#endif
