/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:43:59 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 19:45:43 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_parse		*remove_all(t_parse *head)
{
	t_parse *p;

	while (head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
	return (NULL);
}

int			parse(int argc, char **argv, t_push *ps)
{
	int			i;
	int			k;
	t_parse		*p;
	t_parse		*cp;

	i = 1;
	k = 0;
	p = (t_parse *)malloc(sizeof(t_parse));
	p->next = NULL;
	while (i < argc)
	{
		if (parse_main(argv[i], p) == -1)
			return (ff(p));
		i++;
	}
	cp = p->next;
	while (cp != NULL)
	{
		cp = cp->next;
		k++;
	}
	init(p, ps, k);
	p = remove_all(p);
	return (1);
}

int			parse_main(char *s, t_parse *p)
{
	int v[4];

	init_mv(v);
	while (s[v[0]] != '\0')
	{
		if (s[v[0]] >= '0' && s[v[0]] <= '9')
		{
			v[1] = 0;
			v[0] = ctoi(s, v[0], p, v[2]);
			if (v[0]-- < 0)
				return (-1);
			v[2] = 0;
			v[3] = 1;
		}
		else if (s[v[0]] == '-' && v[1] == 1)
			v[2] = 1;
		else if (s[v[0]] == ' ')
			v[1] = 1;
		else
			return (-1);
		v[0]++;
	}
	if (v[3] == 0)
		return (-1);
	return (1);
}

int			ctoi(char *s, int i, t_parse *p, int f)
{
	long long int	v;
	int				q;

	v = 0;
	q = 0;
	while (s[i] >= '0' && s[i] <= '9' && q < 12 && s[i] != '\0')
	{
		v = (v * 10) + (s[i] - '0');
		q++;
		i++;
	}
	if (f == 1)
		v *= -1;
	if (q > 10 || v < -2147483648 || v > 2147483647)
		return (-1);
	add_elem_parse(p, (int)v);
	return (i);
}

void		add_elem_parse(t_parse *p, int data)
{
	t_parse *tmp;
	t_parse *fk;

	tmp = (t_parse *)malloc(sizeof(t_parse));
	tmp->v = data;
	tmp->next = NULL;
	fk = p;
	while (fk->next != NULL)
	{
		fk = fk->next;
	}
	fk->next = tmp;
}
