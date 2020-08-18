/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:04:44 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/08/16 12:14:51 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	check_map(t_filler *map)
{
	int		m[5];

	m[0] = 2000000;
	m[1] = 0;
	m[3] = 0;
	linefij(map);
	while (m[1] <= (map->n - (map->f_i - map->f_ii + 1)))
	{
		m[2] = 0;
		while (m[2] <= (map->m - (map->f_j - map->f_jj + 1)))
		{
			if (valid_position(map, m[1], m[2]) == 1)
			{
				if (m[0] >= distance_s(map, m[1], m[2]))
				{
					m[0] = distance_s(map, m[1], m[2]);
					m[3] = m[1] - map->f_ii;
					m[4] = m[2] - map->f_jj;
				}
			}
			m[2]++;
		}
		m[1]++;
	}
	print(m[3], m[4]);
}

int		valid_position(t_filler *map, int i, int j)
{
	int		m[5];

	m[0] = map->f_ii;
	m[4] = j;
	m[3] = 0;
	valid_position2(m, i, j, map);
	return (m[3]);
}

void	valid_position2(int m[5], int i, int j, t_filler *map)
{
	while (m[0] <= map->f_i)
	{
		m[1] = map->f_jj;
		j = m[4];
		while (m[1] <= map->f_j)
		{
			if (map->player == 1)
			{
				if (map->map[i][j] == '1' && map->piece[m[0]][m[1]] == '*')
					m[3]++;
				if (map->map[i][j++] == '2' && map->piece[m[0]][m[1]] == '*')
					m[3] = m[3] + 10;
			}
			else if (map->player == 2)
			{
				if (map->map[i][j] == '2' && map->piece[m[0]][m[1]] == '*')
					m[3]++;
				if (map->map[i][j++] == '1' && map->piece[m[0]][m[1]] == '*')
					m[3] = m[3] + 10;
			}
			m[1]++;
		}
		m[0]++;
		i++;
	}
}

void	ox(t_filler *map)
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
			if (map->map[i][j] == (map->rival + '0'))
				map->mas[i][j] = 0;
			else if (map->map[i][j] == (map->player + '0'))
				map->mas[i][j] = -1;
			else if (map->map[i][j] == '.')
				map->mas[i][j] = -2;
			j++;
		}
		i++;
	}
}

int		distance_s(t_filler *map, int i, int j)
{
	int		l;
	int		g;
	int		k;
	int		jj;

	l = map->f_ii;
	k = 0;
	jj = j;
	while (l <= map->f_i)
	{
		g = map->f_jj;
		j = jj;
		while (g <= map->f_j)
		{
			if (map->piece[l][g] == '*')
			{
				k = k + map->mas[i][j];
			}
			g++;
			j++;
		}
		l++;
		i++;
	}
	return (k);
}
