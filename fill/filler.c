/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:05:15 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/08/14 20:27:35 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	re_var(t_filler *map)
{
	int i;

	i = 0;
	map->n = 0;
	map->m = 0;
	map->f_n = 0;
	map->f_m = 0;
	while (i < map->n)
	{
		free(map->map[i]);
		free(map->mas[i]);
		i++;
	}
	while (i < map->f_n)
	{
		free(map->piece[i]);
		i++;
	}
	free(map->map);
	free(map->mas);
	free(map->piece);
}

int		main(void)
{
	t_filler	*map;

	map = (t_filler *)malloc(sizeof(*map));
	def_player(map);
	while (1)
	{
		if (def_plateau(map) == 0)
			exit(1);
		def_map(map);
		def_piece(map);
		def_filler(map);
		check_map(map);
		re_var(map);
	}
	re_var(map);
	free(map);
	return (0);
}

int		def_plateau(t_filler *map)
{
	char	*s;
	int		i;
	int		f;

	f = 0;
	get_next_line(0, &s);
	i = 8;
	if (strncmp(s, "Plateau", 6) == 0 && map->n == 0)
	{
		while (s[i] != '\0')
		{
			if (s[i] == ' ')
			{
				f = 1;
				i++;
			}
			if (f == 0 && (s[i] >= '0' && s[i] <= '9'))
				map->n = (map->n * 10) + (s[i] - '0');
			if (f == 1 && (s[i] >= '0' && s[i] <= '9'))
				map->m = (map->m * 10) + (s[i] - '0');
			i++;
		}
	}
	ft_strdel(&s);
	return (f);
}

int		def_map(t_filler *map)
{
	int		i;
	char	*s;

	i = 0;
	map->map = (char **)malloc(map->n * sizeof(char *));
	map->mas = (int **)malloc(map->n * sizeof(int *));
	while (i < map->n)
	{
		map->map[i] = (char *)malloc(map->m * sizeof(char));
		map->mas[i] = (int *)malloc(map->m * sizeof(int));
		i++;
	}
	i = 0;
	get_next_line(0, &s);
	ft_strdel(&s);
	while (i < map->n)
	{
		get_next_line(0, &s);
		del_mas(s);
		ft_strncpy(map->map[i], s, map->m);
		i++;
		ft_strdel(&s);
	}
	karta(map);
	return (1);
}

void	def_player(t_filler *map)
{
	char *s;

	get_next_line(0, &s);
	if (ft_strncmp(s, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(s, "p1"))
		{
			map->player = 1;
			map->rival = 2;
		}
		else if (ft_strstr(s, "p2"))
		{
			map->player = 2;
			map->rival = 1;
		}
	}
	ft_strdel(&s);
}
