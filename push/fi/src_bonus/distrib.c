/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:36:10 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/10/26 19:07:34 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	mas_preobr(int **pr, int *a, int n)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	while (i < n)
	{
		pr[i][0] = a[i];
		j = 0;
		k = n;
		while (j < n)
		{
			if (pr[i][0] < a[j++])
				k--;
		}
		pr[i][1] = k;
		i++;
	}
}

int		distrib(char *s, int q, int a[1000], int i)
{
	if (s[0] == 's' && s[1] == 'a' && q == 2)
	{
		a[i] = 1;
		return (0);
	}
	else if (s[0] == 's' && s[1] == 'b' && q == 2)
	{
		a[i] = 2;
		return (0);
	}
	else if (s[0] == 's' && s[1] == 's' && q == 2)
	{
		a[i] = 3;
		return (0);
	}
	else if (s[0] == 'p' && s[1] == 'a' && q == 2)
	{
		a[i] = 4;
		return (0);
	}
	return (1);
}

int		distrib2(char *s, int q, int a[1000], int i)
{
	if (s[0] == 'p' && s[1] == 'b' && q == 2)
	{
		a[i] = 5;
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'a' && q == 2)
	{
		a[i] = 6;
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'b' && q == 2)
	{
		a[i] = 7;
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && q == 2)
	{
		a[i] = 8;
		return (0);
	}
	return (1);
}

int		distrib3(char *s, int q, int a[1000], int i)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && q == 3)
	{
		a[i] = 9;
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && q == 3)
	{
		a[i] = 10;
		return (0);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && q == 3)
	{
		a[i] = 11;
		return (0);
	}
	return (1);
}

void	init_m(long m[3])
{
	m[0] = 0;
	m[1] = 0;
	m[2] = 0;
}
