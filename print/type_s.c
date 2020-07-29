
#include "printlib.h"

void	nulls(int m[12])
{
	if (m[7] != 1 || m[6] > 5)
	{
		write(1, "(null)", 6);
		m[11] = m[11] + 6;
	}
}

void	writes(char *s, int m[12])
{
	int		i;

	i = 0;
	while (s[i] != '\0' && i < m[6])
	{
		write(1, &s[i], 1);
		m[11]++;
		i++;
	}
}

int		print_s(int m[8], char *n)
{
	int		k;
	int		f;

	f = 0;
	if (n == NULL)
	{
		f = 1;
		if (m[7] != 1 || m[6] > 5)
			m[6] = 6;
		else
			m[6] = 0;
	}
	else
	{
		k = strlen(n);
		if (m[7] == 0)
			m[6] = k;
		else
		{
			if (k < m[6])
				m[6] = k;
		}
	}
	print_s1(m, n, f);
	return (0);
}

void	print_s1(int m[12], char *n, int f)
{
	if (m[0] == 0)
		writeln(m[5] - m[6], ' ', m);
	if (f == 0)
		writes(n, m);
	else
		nulls(m);
	if (m[0] == 1)
		writeln(m[5] - m[6], ' ', m);
}

int		type_s(va_list *vl, int m[12])
{
	char	*n;

	n = va_arg(*vl, char *);
	print_s(m, n);
	return (0);
}
