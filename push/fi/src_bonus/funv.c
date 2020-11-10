/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:57:21 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/26 19:07:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

int		fun_vpa(t_visual *p)
{
	int i;

	i = p->k_a;
	if (p->k_b > 0)
	{
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = p->b[0];
		while (i < p->k_b - 1)
		{
			p->b[i] = p->b[i + 1];
			i++;
		}
		p->k_b--;
		p->k_a++;
	}
	return (0);
}

int		fun_vpb(t_visual *p)
{
	int i;

	i = p->k_b;
	if (p->k_a > 0)
	{
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = p->a[0];
		while (i < p->k_a - 1)
		{
			p->a[i] = p->a[i + 1];
			i++;
		}
		p->k_a--;
		p->k_b++;
	}
	return (0);
}

int		fun_vra(t_visual *p)
{
	int i;
	int n;

	n = p->a[0];
	i = 0;
	if (p->k_a > 1)
	{
		while (i < p->k_a - 1)
		{
			p->a[i] = p->a[i + 1];
			i++;
		}
		p->a[p->k_a - 1] = n;
	}
	return (0);
}

int		fun_vrb(t_visual *p)
{
	int i;
	int n;

	n = p->b[0];
	i = 0;
	if (p->k_b > 1)
	{
		while (i < p->k_b - 1)
		{
			p->b[i] = p->b[i + 1];
			i++;
		}
		p->b[p->k_b - 1] = n;
	}
	return (0);
}

int		fun_vrra(t_visual *p)
{
	int i;
	int n;

	n = p->a[p->k_a - 1];
	i = p->k_a - 1;
	if (p->k_a > 1)
	{
		while (i > 0)
		{
			p->a[i] = p->a[i - 1];
			i--;
		}
		p->a[0] = n;
	}
	return (0);
}
