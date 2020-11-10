/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 20:32:46 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/31 20:32:50 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_memory(t_push *p, int f)
{
	int i;

	i = 0;
	if (f == 1)
	{
		while (i < p->k)
			free(p->ab[i++]);
		free(p->ab);
	}
	free(p->a);
	free(p->b);
}

int		main(int argc, char **argv)
{
	t_push *p;

	if (argc < 2)
		return (0);
	p = (t_push*)malloc(sizeof(*p));
	if (parse(argc, argv, p) == 0)
	{
		write(1, "Error\n", 6);
		free(p);
		return (0);
	}
	if (check_replay(p->a, p->k_a) == 0)
	{
		write(1, "Error\n", 6);
		free_memory(p, 0);
		free(p);
		return (0);
	}
	mas_pair(p);
	alg(p);
	free_memory(p, 1);
	free(p);
	return (0);
}
