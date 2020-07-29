#include "printlib.h"

void	signf(double n, int f1, int f2)
{
	if (n < 0)
		write(1, "-", 1);
	else
	{
		if (f1 == 1)
			write(1, "+", 1);
		if (f2 == 1)
			write(1, " ", 1);
	}
}

void	f1(char a[100])
{
	int		i;

	i = 0;
	while (i < 100)
		a[i++] = '.';
}


void	print_d1(char a[21], int m[12])
{
	int		i;

	i = 20;
	while (i >= 0)
	{
		if (a[i] != '.')
		{
			write(1, &a[i], 1);
			m[11]++;
		}
		i--;
	}
}

void	print_f1(char a[100])
{
	int		i;

	i = 0;
	while (i < 100)
	{
		if (('0' <= a[i]) && (a[i] <= '9'))
			write(1, &a[i], 1);
		i++;
	}
}

void	check_f(int m[12], long long r, double n)
{
	if (r % 2 != 0)
	{
		if ((long long)(n * 10) >= 5)
			m[10] = 1;
	}
	else
	{
		if ((long long)(n * 10) > 5)
			m[10] = 1;
	}
}

void	pr_inf(int m[12], char a[21], double n)
{
	a[20] = 'i';
	a[19] = 'n';
	a[18] = 'f';
	m[9] = 3;
	m[6] = 0;
	if (n < 0)
		if (m[2] != 1)
			m[1] = 1;
}
