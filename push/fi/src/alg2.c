/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:21:30 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/05 16:28:05 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	predvartwo3(t_push *p)
{
	while (mesto(p->b, 0, p->k_b - 1, p->a[1]) == 0
			&& !(p->a[1] > p->a[0] && mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
	{
		fun_sa(p);
		fun_pb(p);
	}
}

void	predvartwo2(t_push *p)
{
	if (p->a[p->k_a - 1] < p->a[1])
	{
		while (mesto(p->b, 0, p->k_b - 1, p->a[p->k_a - 1]) == 0
			&& p->k_a > 1 && !(p->a[p->k_a - 1] > p->a[0]
			&& mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
			fun_rra(p, 0);
	}
	else
	{
		while (mesto(p->b, 0, p->k_b - 1, p->a[1]) == 0
				&& p->k_a > 1 && !(p->a[1] > p->a[0] &&
				mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
		{
			fun_sa(p);
			fun_pb(p);
		}
	}
}

void	predvartwo1(t_push *p, int a, int b)
{
	while ((a == 1 || b == 1) && p->k_a > 1)
	{
		if (a == 1 && b == 1)
			predvartwo2(p);
		else if (a == 1 && b != 1)
		{
			while (mesto(p->b, 0, p->k_b - 1, p->a[p->k_a - 1]) == 0
					&& p->k_a > 1 && !(p->a[p->k_a - 1] > p->a[0] &&
					mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
				fun_rra(p, 0);
		}
		else if (a != 1 && b == 1)
			predvartwo3(p);
		a = 0;
		b = 0;
		if (mesto(p->b, 0, p->k_b - 1, p->a[p->k_a - 1]) == 0
			&& !(p->a[p->k_a - 1] > p->a[0]
			&& mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
			a = 1;
		if (mesto(p->b, 0, p->k_b - 1, p->a[1]) == 0 && !(p->a[1] > p->a[0]
			&& mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
			b = 1;
		if (mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0)
			fun_pb(p);
	}
}

int		predvartwo(t_push *p)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (mesto(p->b, 0, p->k_b - 1, p->a[p->k_a - 1]) == 0
		&& !(p->a[p->k_a - 1] > p->a[0]
		&& mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
		a = 1;
	if (mesto(p->b, 0, p->k_b - 1, p->a[1]) == 0
		&& !(p->a[1] > p->a[0] && mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0))
		b = 1;
	predvartwo1(p, a, b);
	if (mesto(p->b, 0, p->k_b - 1, p->a[0]) == 0 ||
	mesto(p->b, 0, p->k_b - 1, p->a[0]) == p->k_b)
	{
		fun_pb(p);
	}
	return (0);
}

int		fun_rrr(t_push *p)
{
	fun_rra(p, 1);
	fun_rrb(p, 1);
	write(1, "rrr\n", 4);
	p->i++;
	return (0);
}
