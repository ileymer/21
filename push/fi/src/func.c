/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:11:16 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:26:12 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		fun_cpa(t_push *p)
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

int		fun_cpb(t_push *p)
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

int		fun_cra(t_push *p)
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
		p->i++;
	}
	return (0);
}

int		fun_crb(t_push *p)
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
		p->i++;
	}
	return (0);
}

int		fun_crra(t_push *p)
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
		p->i++;
	}
	return (0);
}
