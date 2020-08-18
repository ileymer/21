/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 20:02:53 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/08/16 12:14:19 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	def_piece(t_filler *map)
{
	char	*s;
	int		i;
	int		f;

	f = 0;
	get_next_line(0, &s);
	i = 6;
	if (ft_strncmp(s, "Piece", 4) == 0)
	{
		while (s[i] != '\0')
		{
			if (s[i] == ' ')
			{
				f = 1;
				i++;
			}
			if (f == 0 && (s[i] >= '0' && s[i] <= '9'))
				map->f_n = (map->f_n * 10) + (s[i] - '0');
			if (f == 1 && (s[i] >= '0' && s[i] <= '9'))
				map->f_m = (map->f_m * 10) + (s[i] - '0');
			i++;
		}
	}
	ft_strdel(&s);
}

int		def_filler(t_filler *map)
{
	int		i;
	char	*s;

	i = 0;
	map->piece = (char **)malloc(map->f_n * sizeof(char *));
	while (i < map->f_n)
		map->piece[i++] = (char *)malloc(map->f_m * sizeof(char));
	i = 0;
	while (i < map->f_n)
	{
		get_next_line(0, &s);
		ft_strncpy(map->piece[i], s, map->f_m);
		i++;
		ft_strdel(&s);
	}
	return (1);
}

void	del_mas(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '.' && s[i] != 'o' && s[i] != 'O' &&  \
			s[i] != 'X' && s[i] != 'x' && s[i] != '\0')
	{
		i++;
	}
	while (s[j] != '\0')
	{
		s[j] = s[i];
		if (s[j] == 'o' || s[j] == 'O')
			s[j] = '1';
		else if (s[j] == 'x' || s[j] == 'X')
			s[j] = '2';
		i++;
		j++;
	}
}

void	print(int x, int y)
{
	if (x != 0 || y !=0)
	{
		ft_putnbr(x);
		ft_putchar(' ');
		ft_putnbr(y);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
}
