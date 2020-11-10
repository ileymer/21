/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:59:48 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/26 19:07:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int		fun_vrrb(t_visual *p)
{
	int i;
	int n;

	n = p->b[p->k_b - 1];
	i = p->k_b - 1;
	if (p->k_b > 1)
	{
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = n;
	}
	return (0);
}

int		fun_vsa(t_visual *p)
{
	int k;

	if (p->k_a > 1)
	{
		k = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = k;
	}
	return (0);
}

int		fun_vsb(t_visual *p)
{
	int k;

	if (p->k_b > 0)
	{
		k = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = k;
	}
	return (0);
}
