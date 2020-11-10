/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:13:02 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 19:58:24 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		fun_crrb(t_push *p)
{
	int i;
	int n;

	n = p->b[p->k_b - 1];
	i = p->k_b - 1;
	if (p->k_b > 1)
	{
		while (i > 0)
		{
			p->b[i] = p->b[i - 1];
			i--;
		}
		p->b[0] = n;
		p->i++;
	}
	return (0);
}

int		fun_csa(t_push *p)
{
	int k;

	if (p->k_a > 1)
	{
		k = p->a[0];
		p->a[0] = p->a[1];
		p->a[1] = k;
		p->i++;
	}
	return (0);
}

int		fun_csb(t_push *p)
{
	int k;

	if (p->k_b > 0)
	{
		k = p->b[0];
		p->b[0] = p->b[1];
		p->b[1] = k;
		p->i++;
	}
	return (0);
}

void	free_memorys(t_push *p, char *s)
{
	int		i;

	i = 0;
	free(p->a);
	free(p->b);
	ft_strdel(&s);
	free(p);
}

int		distrib3(char *s, int q, t_push *p)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && q == 3)
	{
		fun_crra(p);
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && q == 3)
	{
		fun_crrb(p);
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && q == 3)
	{
		fun_crra(p);
		fun_crrb(p);
		return (0);
	}
	return (1);
}
