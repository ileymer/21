/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:06:31 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/26 19:07:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	run(t_visual *p)
{
	if (p->mr[p->i[0]] == 1)
	{
		fun_vsa(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "SA");
	}
	else if (p->mr[p->i[0]] == 2)
	{
		fun_vsb(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "SB");
	}
	else if (p->mr[p->i[0]] == 3)
	{
		fun_vsa(p);
		fun_vsb(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "SS");
	}
	else if (p->mr[p->i[0]] == 4)
	{
		fun_vpa(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "PA");
	}
}

void	run2(t_visual *p)
{
	if (p->mr[p->i[0]] == 5)
	{
		fun_vpb(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "PB");
	}
	else if (p->mr[p->i[0]] == 6)
	{
		fun_vra(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "RA");
	}
	else if (p->mr[p->i[0]] == 7)
	{
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "RB");
		fun_vrb(p);
	}
	else if (p->mr[p->i[0]] == 8)
	{
		fun_vra(p);
		fun_vrb(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1240, 650, 0x800080, "RR");
	}
}

void	run3(t_visual *p)
{
	if (p->mr[p->i[0]] == 9)
	{
		fun_vrra(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1235, 650, 0x800080, "RRA");
	}
	else if (p->mr[p->i[0]] == 10)
	{
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1235, 650, 0x800080, "RRB");
		fun_vrrb(p);
	}
	else if (p->mr[p->i[0]] == 11)
	{
		fun_vrra(p);
		fun_vrrb(p);
		mlx_string_put(p->mlx_ptr, p->win_ptr, 1235, 650, 0x800080, "RRR");
	}
	p->i[0]++;
}

int		*m4(int x, int y, int lx, int ly)
{
	int *m;

	m = (int *)malloc(4 * sizeof(int));
	m[0] = x;
	m[1] = y;
	m[2] = lx;
	m[3] = ly;
	return (m);
}
