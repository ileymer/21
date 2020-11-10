/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:54:07 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:03:40 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		fun_sa(t_push *p)
{
	int k;

	if (p->k_a > 1)
	{
		k = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = k;
		p->i++;
		write(1, "sa\n", 3);
	}
	return (0);
}

int		fun_sb(t_push *p)
{
	int k;

	if (p->k_b > 1)
	{
		write(1, "sb\n", 3);
		k = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = k;
		p->i++;
	}
	return (0);
}

int		fun_ss(t_push *p)
{
	int k;

	if (p->k_b > 1 && p->k_a > 1)
	{
		write(1, "ss\n", 3);
		k = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = k;
		k = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = k;
		p->i++;
	}
	return (0);
}

int		fun_pa(t_push *p)
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
		p->i++;
		write(1, "pa\n", 3);
	}
	return (0);
}

int		fun_pb(t_push *p)
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
		p->i++;
		write(1, "pb\n", 3);
	}
	return (0);
}
