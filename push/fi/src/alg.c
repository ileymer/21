/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:02:34 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:17:47 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		alg(t_push *p)
{
	p->k_a = p->k;
	p->k_b = 0;
	while (p->k_a > 3 && check(p->a, p->k_a) == 0)
	{
		predvartwox(p);
		predvartwo(p);
	}
	max_mesto(p);
	if (check(p->a, p->k_a) != 1)
		alignment_a(p);
	if (check(p->a, p->k_a) == 1 && p->k_b == 0)
		return (0);
	theend(p);
	return (0);
}

void	alignment_a(t_push *p)
{
	if (p->k_a == 3)
	{
		if (p->a[0] > p->a[1] && p->a[0] > p->a[2] && p->a[2] > p->a[1])
		{
			fun_ra(p, 0);
		}
		else if (p->a[0] > p->a[1] && p->a[0] < p->a[2] && p->a[2] > p->a[1])
		{
			fun_sa(p);
		}
		else if (p->a[0] < p->a[1] && p->a[0] > p->a[2] && p->a[2] < p->a[1])
		{
			fun_rra(p, 0);
		}
		else if (p->a[0] < p->a[1] && p->a[0] < p->a[2] && p->a[2] < p->a[1])
		{
			fun_rra(p, 0);
			fun_sa(p);
		}
		else if (p->a[0] > p->a[1] && p->a[0] > p->a[2] && p->a[2] < p->a[1])
		{
			fun_sa(p);
			fun_rra(p, 0);
		}
	}
}

int		theend(t_push *p)
{
	int i;
	int j;

	i = 0;
	if (maxs(p->b, p->k_b, p->a[p->k_a - 1]) == 1)
		fun_rra(p, 0);
	j = imas(p->ab, p->k, p->a[p->k_a - 1]);
	while (p->k_b > 0)
	{
		while (p->ab[j][2] == p->a[0])
		{
			fun_rra(p, 0);
			j = imas(p->ab, p->k, p->a[p->k_a - 1]);
		}
		fun_pa(p);
		i++;
	}
	while (p->ab[j][2] == p->a[0])
	{
		fun_rra(p, 0);
		j = imas(p->ab, p->k, p->a[p->k_a - 1]);
	}
	return (0);
}

int		maxs(int *a, int k, int n)
{
	int i;

	i = 0;
	while (i < k)
	{
		if (a[i++] > n)
			return (0);
	}
	return (1);
}

int		mesto(int *m, int n, int k, int a)
{
	int l[5];

	mesto_in(l);
	while (n < k)
	{
		if (m[n] > a && m[n + 1] < a)
			return (n + 1);
		n++;
	}
	while (l[2] <= k)
	{
		mesto1(l, m);
		l[2]++;
	}
	if (a > l[0])
		return (l[3]);
	if (a < l[1])
		return (l[4] + 1);
	return (0);
}
