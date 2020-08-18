/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:07:15 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/08/14 20:26:26 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		karta(t_filler *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	ox(map);
	while (check_two(map) && k < 1000)
	{
		i = 0;
		while (i < map->n)
		{
			j = 0;
			while (j < map->m)
			{
				if (map->mas[i][j] == k)
					distrib_weight(map, i, j, k + 1);
				j++;
			}
			i++;
		}
		k++;
	}
	return (0);
}

void	distrib_weight(t_filler *map, int i, int j, int k)
{
	if (i != 0 && j != 0)
	{
		if (map->mas[i - 1][j - 1] == -2)
			map->mas[i - 1][j - 1] = k;
	}
	if (i != 0)
	{
		if (map->mas[i - 1][j] == -2)
			map->mas[i - 1][j] = k;
	}
	if ((i != 0) && (j != map->m - 1))
	{
		if (map->mas[i - 1][j + 1] == -2)
			map->mas[i - 1][j + 1] = k;
	}
	if (j != 0)
	{
		if (map->mas[i][j - 1] == -2)
			map->mas[i][j - 1] = k;
	}
	distrib_weight2(map, i, j, k);
}

void	distrib_weight2(t_filler *map, int i, int j, int k)
{
	if (j != map->m - 1)
	{
		if (map->mas[i][j + 1] == -2)
			map->mas[i][j + 1] = k;
	}
	if (i != map->n - 1 && j != 0)
	{
		if (map->mas[i + 1][j - 1] == -2)
			map->mas[i + 1][j - 1] = k;
	}
	if (i != map->n - 1)
	{
		if (map->mas[i + 1][j] == -2)
			map->mas[i + 1][j] = k;
	}
	if (i != map->n - 1 && j != map->n - 1)
	{
		if (map->mas[i + 1][j + 1] == -2)
			map->mas[i + 1][j + 1] = k;
	}
}

int		check_two(t_filler *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->n)
	{
		j = 0;
		while (j < map->m)
		{
			if (map->mas[i][j] == -2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
