/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:53:16 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:03:40 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	predvartwox2(t_push *p, int l[13])
{
	int i;

	i = 0;
	while (i <= p->k_a / 2)
	{
		l[2] = mesto(p->b, 0, p->k_b - 1, p->a[i]);
		if (l[2] == p->k_b || l[2] == 0)
			l[2] = 0;
		else if (l[2] > p->k_b / 2)
		{
			l[2] = p->k_b - l[2];
			l[8] = 1;
		}
		l[3] = l[2] + i;
		if (l[0] > l[3])
		{
			l[0] = l[3];
			l[4] = i;
			l[5] = l[2];
			l[9] = l[8];
		}
		l[8] = 0;
		i++;
	}
}

void	predvartwox3(t_push *p, int l[13])
{
	int i;

	i = p->k_a / 2;
	while (i < p->k_a)
	{
		l[2] = mesto(p->b, 0, p->k_b - 1, p->a[i]);
		if (l[2] == p->k_b || l[2] == 0)
			l[2] = 0;
		else if (l[2] > p->k_b / 2)
		{
			l[2] = p->k_b - l[2];
			l[10] = 1;
		}
		l[3] = l[2] + i;
		if (l[1] > l[3])
		{
			l[1] = l[3];
			l[7] = p->k_a - i;
			l[6] = l[2];
			l[10] = l[11];
		}
		i++;
	}
}

void	predvartwox41(t_push *p, int l[13], int i)
{
	if (l[9] == 0)
	{
		if (l[4] < l[5])
			l[12] = l[4];
		else if (l[4] > l[5])
			l[12] = l[5];
		else
			l[12] = l[5];
		while (i++ < l[12])
			fun_rr(p);
		i = 0;
		while (i++ < l[5] - l[4])
			fun_rb(p, 0);
		i = 0;
		while (i++ < l[4] - l[5])
			fun_ra(p, 0);
	}
	else
	{
		while (i++ < l[4])
			fun_ra(p, 0);
		i = 0;
		while (i++ < l[5])
			fun_rrb(p, 0);
	}
}

void	predvartwox42(t_push *p, int l[13], int i)
{
	if (l[11] != 0)
	{
		if (l[7] < l[6])
			l[12] = l[7];
		else if (l[7] > l[6])
			l[12] = l[6];
		else
			l[12] = l[6];
		while (i++ < l[12])
			fun_rrr(p);
		i = 0;
		while (i++ < l[6] - l[7])
			fun_rrb(p, 0);
		i = 0;
		while (i++ < l[7] - l[6])
			fun_rra(p, 0);
	}
	else
	{
		while (i++ < l[7])
			fun_rra(p, 0);
		i = 0;
		while (i++ < l[6])
			fun_rb(p, 0);
	}
}

int		predvartwox(t_push *p)
{
	int	l[13];

	l[0] = 2000000;
	l[1] = 2000000;
	l[2] = 0;
	l[3] = -1;
	l[4] = 0;
	l[5] = 0;
	l[6] = 0;
	l[7] = 0;
	l[8] = 0;
	l[9] = 0;
	l[10] = 0;
	l[11] = 0;
	l[12] = 0;
	predvartwox2(p, l);
	predvartwox3(p, l);
	if (l[3] != -1)
	{
		if (l[0] < l[1])
			predvartwox41(p, l, 0);
		else
			predvartwox42(p, l, 0);
	}
	return (1000000);
}
