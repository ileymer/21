/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:30:44 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/24 14:03:40 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		fun_ra(t_push *p, int f)
{
	int i;
	int n;

	n = p->a[0];
	i = 0;
	while (i < p->k_a - 1)
	{
		p->a[i] = p->a[i + 1];
		i++;
	}
	p->a[p->k_a - 1] = n;
	if (f == 0)
	{
		write(1, "ra\n", 3);
		p->i++;
	}
	return (0);
}

int		fun_rb(t_push *p, int f)
{
	int i;
	int n;

	n = p->b[0];
	i = 0;
	while (i < p->k_b - 1)
	{
		p->b[i] = p->b[i + 1];
		i++;
	}
	p->b[p->k_b - 1] = n;
	if (f == 0)
	{
		write(1, "rb\n", 3);
		p->i++;
	}
	return (0);
}

int		fun_rra(t_push *p, int f)
{
	int i;
	int n;

	n = p->a[p->k_a - 1];
	i = p->k_a - 1;
	while (i > 0)
	{
		p->a[i] = p->a[i - 1];
		i--;
	}
	p->a[0] = n;
	if (f == 0)
	{
		write(1, "rra\n", 4);
		p->i++;
	}
	return (0);
}

int		fun_rrb(t_push *p, int f)
{
	int i;
	int n;

	n = p->b[p->k_b - 1];
	i = p->k_b - 1;
	while (i > 0)
	{
		p->b[i] = p->b[i - 1];
		i--;
	}
	p->b[0] = n;
	if (f == 0)
	{
		p->i++;
		write(1, "rrb\n", 4);
	}
	return (0);
}

int		fun_rr(t_push *p)
{
	fun_ra(p, 1);
	fun_rb(p, 1);
	write(1, "rr\n", 3);
	p->i++;
	return (0);
}
