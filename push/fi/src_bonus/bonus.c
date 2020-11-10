/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:12 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/27 15:31:15 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	v_init(t_visual *p, int argc)
{
	int i;

	i = 0;
	p->a = (int *)malloc((argc - 1) * sizeof(int));
	p->b = (int *)malloc((argc - 1) * sizeof(int));
	p->pr = (int **)malloc((argc - 1) * sizeof(int *));
	p->k = argc - 1;
	p->k_a = argc - 1;
	p->k_b = 0;
	p->i[0] = 0;
	while (i < p->k_a)
	{
		p->pr[i] = (int *)malloc((2) * sizeof(int));
		i++;
	}
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, 2500, 1300, "nax");
}

void	free_mem(t_visual *p)
{
	int i;

	i = 0;
	free(p->a);
	free(p->b);
	while (i < p->k)
		free(p->pr[i++]);
	free(p);
}

int		ctoi_main(char **argv, t_visual *p, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ctoi(argv[i], p, i - 1) != 1)
			return (0);
		i++;
	}
	return (1);
}

int		ctoi(char *s, t_visual *p, int j)
{
	long	m[3];

	init_m(m);
	if (s[m[0]] == '-')
	{
		m[1] = 1;
		m[0]++;
	}
	while (s[m[0]] != '\0' && m[0] < 11)
		if ('0' <= s[m[0]] && s[m[0]++] <= '9')
			m[2] = (m[2] * 10) + (s[m[0] - 1] - '0');
		else
			return (0);
	if (m[1] == 1)
		m[2] = m[2] * (-1);
	if (m[0] == 0)
		return (0);
	if (m[1] == 1 && m[0] == 1)
		return (0);
	if (-2147483648 <= m[2] && m[2] <= 2147483647)
		p->a[j] = m[2];
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_visual	*p;
	char		*s;
	int			q;
	int			i;

	i = 0;
	p = (t_visual *)malloc(sizeof(*p));
	v_init(p, argc);
	if (argc < 2 || ctoi_main(argv, p, argc) == 0)
		return (0);
	mas_preobr(p->pr, p->a, p->k);
	while (get_next_line(0, &s))
	{
		q = ft_strlen(s);
		if (distrib(s, q, p->mr, i) && distrib2(s, q, p->mr, i)
			&& distrib3(s, q, p->mr, i))
		{
			return (0);
		}
		i++;
	}
	mlx_key_hook(p->win_ptr, vivviz, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
