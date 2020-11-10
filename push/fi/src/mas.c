/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 07:29:04 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:03:40 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		imas(int **a, int k, int n)
{
	int i;

	i = 0;
	while (i < k)
	{
		if (a[i][1] == n)
			return (i);
		i++;
	}
	return (0);
}

int		max_m(int *a, int k)
{
	int i;
	int j;
	int m;

	i = 0;
	j = 0;
	m = -2147483648;
	while (i < k)
	{
		if (a[i] > m)
		{
			m = a[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int		mas_pair(t_push *p)
{
	int i;

	i = 0;
	p->ab = (int **)malloc(p->k * sizeof(int *));
	while (i < p->k)
	{
		p->ab[i] = (int*)malloc(3 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < p->k)
	{
		p->ab[i][0] = min_pair(p->a[i], p);
		p->ab[i][1] = p->a[i];
		p->ab[i][2] = max_pair(p->a[i], p);
		i++;
	}
	return (0);
}

int		min_pair(int n, t_push *p)
{
	int i;
	int m;

	m = 0;
	i = 0;
	while (i < p->k)
	{
		if (p->a[i] < n)
		{
			if (m < p->a[i])
			{
				m = p->a[i];
			}
		}
		i++;
	}
	return (m);
}

int		max_pair(int n, t_push *p)
{
	int i;
	int m;

	m = 2000000000;
	i = 0;
	while (i < p->k)
	{
		if (p->a[i] > n)
		{
			if (m > p->a[i])
			{
				m = p->a[i];
			}
		}
		i++;
	}
	return (m);
}
