/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:22:58 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 19:50:07 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_replay(int *m, int k)
{
	int i;
	int j;
	int r;

	i = 0;
	j = 0;
	r = 0;
	while (i < k)
	{
		r = 0;
		j = 0;
		while (j < k)
		{
			if (m[i] == m[j++])
				r++;
		}
		if (r > 1)
			return (0);
		i++;
	}
	return (1);
}

void	init(t_parse *parse, t_push *p, int k)
{
	int		i;
	t_parse *tmp;

	i = 0;
	p->k = k;
	p->i = 1;
	p->k_a = p->k;
	p->k_b = 0;
	p->a = (int *)malloc(p->k * sizeof(int));
	p->b = (int *)malloc(p->k * sizeof(int));
	tmp = parse;
	tmp = tmp->next;
	while (i < p->k)
	{
		p->a[i++] = tmp->v;
		tmp = tmp->next;
	}
}

void	init_mv(int v[4])
{
	v[0] = 0;
	v[1] = 1;
	v[2] = 0;
	v[3] = 0;
}

int		check(int *s, int k)
{
	int i;
	int j;

	i = 1;
	while (i < k)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (s[j--] > s[i])
				return (0);
		}
		i++;
	}
	return (1);
}

int		ff(t_parse *p)
{
	p = remove_all(p);
	free(p);
	return (0);
}
