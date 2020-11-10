/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:04:20 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/11/10 11:32:58 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mesto_in(int l[5])
{
	l[0] = -2147483648;
	l[1] = 2147483647;
	l[2] = 0;
	l[3] = 0;
	l[4] = 0;
}

void	mesto1(int l[5], int *m)
{
	if (l[0] < m[l[2]])
	{
		l[0] = m[l[2]];
		l[3] = l[2];
	}
	if (l[1] > m[l[2]])
	{
		l[1] = m[l[2]];
		l[4] = l[2];
	}
}

int		max_mesto(t_push *p)
{
	int j;

	j = max_m(p->b, p->k_b);
	if (j == 0)
		return (0);
	else
	{
		if (j <= p->k_b / 2)
			while (j-- > 0)
				fun_rb(p, 0);
		else
		{
			j = p->k_b - j;
			while (j-- > 0)
				fun_rrb(p, 0);
		}
	}
	return (0);
}
