/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:45:12 by dgeonosi          #+#    #+#             */
/*   Updated: 2020/07/29 12:45:21 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"

int		fttoc1(char t[100], int j)
{
	int		f;

	f = 1;
	while (j >= 0)
	{
		if (48 <= t[j] && t[j] < 57 && f == 1)
		{
			t[j]++;
			f = 0;
		}
		if (t[j] == '9' && f == 1)
		{
			t[j] = 48;
			if (j == 0)
				return (1);
		}
		j--;
	}
	return (0);
}

int		fttoc(char t[100], double n, long long r, int m[12])
{
	long long	k;
	int			p;
	int			j;

	j = 0;
	p = m[6];
	if (n < 0)
		n = n * (-1);
	k = (long long)n;
	n = n - (double)(k);
	check_f(m, r, n);
	while (p-- > 0 && j < 100)
	{
		n = n * 10;
		k = (long long)(n);
		if (j == 0 && k >= 5)
			m[10] = 1;
		t[j++] = k + '0';
		n = n - (double)(k);
	}
	if ((int)(n * 10) >= 5)
		m[8] = fttoc1(t, --j);
	return (0);
}

int		print_f(char t[100], int m[12], char a[21], double n)
{
	if ((m[6] != 0 || m[7] == 0 || m[3] == 1) && (a[20] != 'i'))
		m[12] = 1;
	if (m[0] == 0)
		if (m[4] == 1)
		{
			signf(n, m[1], m[2]);
			writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], '0', m);
		}
		else
		{
			writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], ' ', m);
			signf(n, m[1], m[2]);
		}
	if (m[0] == 1)
		signf(n, m[1], m[2]);
	print_d1(a, m);
	if (m[12] == 1)
	{
		writeln(1, '.', m);
		print_f1(t);
	}
	writeln(m[6] - 100, '0', m);
	if (m[0] == 1)
		writeln(m[5] - m[6] - m[1] - m[2] - m[9] - m[12], ' ', m);
}

int		type_f(va_list *vl, int m[12])
{
	double			n;
	long long int	k;
	char			a[21];
	char			t[100];

	n = (double)(va_arg(*vl, double));
	di1(a);
	f1(t);
	if (-9223372036854775700.0 < n && n < 9223372036854775700.0)
	{
		if (m[6] == 0 && m[7] == 0)
			m[6] = 6;
		k = n;
		fttoc(t, n, k, m);
		if (m[6] == 0 && m[7] == 1 && m[10] == 1)
			m[8]++;
		if (n < 0)
			m[8] = m[8] * (-1);
		m[9] = ftoc(a, k + m[8], m);
	}
	else
		pr_inf(m, a, n);
	print_f(t, m, a, n);
}

int		ftoc(char a[21], long long int n, int m[12])
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	if (n < 0)
	{
		if (m[2] != 1)
			m[1] = 1;
		n = n * (-1);
	}
	if (n == 0)
	{
		k++;
		a[i] = '0';
	}
	while (n > 0)
	{
		a[i++] = (n % 10) + '0';
		n = n / 10;
		k++;
	}
	return (k);
}
