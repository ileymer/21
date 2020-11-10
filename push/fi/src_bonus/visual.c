/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:02:45 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/26 19:07:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int		pixel_print(t_visual *s, int *m, int color)
{
	int		x;
	int		y;

	x = m[0];
	y = m[1];
	while (x < m[0] + m[2])
	{
		y = m[1];
		while (y < m[1] + m[3])
		{
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, x, y, color);
			y++;
		}
		x++;
	}
	free(m);
	return (0);
}

void	visual(t_visual *p)
{
	pixel_print(p, m4(0, 0, 2500, 2500), 0x45CEA2);
	pixel_print(p, m4(0, 0, 2500, 50), 0xA8E4A0);
	pixel_print(p, m4(1225, 0, 50, 2500), 0xA8E4A0);
	pixel_print(p, m4(0, 1250, 2500, 50), 0xA8E4A0);
}

void	viviz_a(t_visual *p, int b, int r, int a)
{
	int i;
	int j;

	i = 0;
	while (i < p->k_a)
	{
		j = 0;
		while (j < p->k)
		{
			if (p->pr[j][0] == p->a[i])
			{
				pixel_print(p, m4(0, b, p->pr[j][1] * r, a), b);
				b = b + a;
			}
			j++;
		}
		i++;
	}
}

void	viviz_b(t_visual *p, int b, int r, int a)
{
	int i;
	int j;

	i = 0;
	while (i < p->k_b)
	{
		j = 0;
		while (j < p->k)
		{
			if (p->pr[j][0] == p->b[i])
			{
				pixel_print(p, m4(1275, b, p->pr[j][1] * r, a), b);
				b = b + a;
			}
			j++;
		}
		i++;
	}
}

int		vivviz(int key, t_visual *p)
{
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		free_mem(p);
		exit(0);
	}
	mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 1000, 0xFFFFFF, "davay");
	if (key == 36)
	{
		mlx_clear_window(p->mlx_ptr, p->win_ptr);
		visual(p);
		viviz_a(p, 50, 1225 / p->k, 1200 / p->k);
		viviz_b(p, 50, 1225 / p->k, 1200 / p->k);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 600, 10, 0xB32821, "STACK  A");
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1800, 10, 0xB32800, "STACK  B");
		run(p);
		run2(p);
		run3(p);
	}
	return (0);
}
