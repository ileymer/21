/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:19:20 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 20:31:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print(int f, t_push *p, char *s)
{
	if (f == 1)
		write(1, "OK\n", 3);
	if (f == 0)
	{
		write(1, "Error\n", 6);
		free_memorys(p, s);
		exit(0);
	}
	if (f == 2)
		write(1, "KO\n", 3);
	free_memorys(p, s);
}

void	printik(t_push *p, char *s)
{
	if (check(p->a, p->k_a) == 1 && p->k_b == 0)
		print(1, p, s);
	else
		print(2, p, s);
}

int		main(int argc, char **argv)
{
	t_push	*p;
	char	*s;

	if (argc < 2)
		return (0);
	p = (t_push *)malloc(sizeof(*p));
	if (parse(argc, argv, p) == 0)
	{
		write(1, "Error\n", 6);
		free(p);
		return (0);
	}
	if (check_replay(p->a, p->k_a) == 0)
		fff(p);
	while (get_next_line(0, &s))
	{
		if (distrib(s, ft_strlen(s), p) == 1 &&
					distrib2(s, ft_strlen(s), p) == 1
					&& distrib3(s, ft_strlen(s), p) == 1)
			print(0, p, s);
		ft_strdel(&s);
	}
	printik(p, s);
	return (0);
}

int		distrib(char *s, int q, t_push *p)
{
	if (s[0] == 's' && s[1] == 'a' && q == 2)
	{
		fun_csa(p);
		return (0);
	}
	else if (s[0] == 's' && s[1] == 'b' && q == 2)
	{
		fun_csb(p);
		return (0);
	}
	else if (s[0] == 's' && s[1] == 's' && q == 2)
	{
		fun_csa(p);
		fun_csb(p);
		return (0);
	}
	else if (s[0] == 'p' && s[1] == 'a' && q == 2)
	{
		fun_cpa(p);
		return (0);
	}
	return (1);
}

int		distrib2(char *s, int q, t_push *p)
{
	if (s[0] == 'p' && s[1] == 'b' && q == 2)
	{
		fun_cpb(p);
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'a' && q == 2)
	{
		fun_cra(p);
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'b' && q == 2)
	{
		fun_crb(p);
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && q == 2)
	{
		fun_cra(p);
		fun_crb(p);
		return (0);
	}
	return (1);
}
