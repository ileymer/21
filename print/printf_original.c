#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>


int     fttoc1(char t[100], int j);
int     fttoc(char t[100], float  n, int m[12]);
int     print_f(char t[100], int m[12], char a[21], float  n);
int     type_f(va_list *vl, int m[12]);
void     print_f1(char a[100]);
void signf(float n, int f1, int f2);
void    f1(char a[100]);
int    ftoc(char a[21], long long int n, int m[12]);



int     flag1(char c)
{
    if (c == '-' || c == ' ' || c == '+' || c == '#' || c == '0')
        return (1);
    return (0);
}

void writeln(int n, char c, int m[12])
{
    while (n-- > 0)
    {
        write(1, &c, 1);
        m[11]++;
    }
}

void nol(int m[12])
{
    int i = 0;
    while (i < 12)
        m[i++] = 0;
}

void    di1(char a[21])
{
    int i;

    i = 0;
    while (i < 21)
        a[i++] = '.';
}


void signdi(int n, int f1, int f2,int m[12])
{
    if (n < 0 )
    {
        write(1, "-", 1);
        m[11]++;
    }
    else
    {
        if (f1 == 1)
        {
            write(1, "+", 1);
            m[11]++;
        }
        if (f2 == 1)
        {
            write(1, " ", 1);
            m[11]++;
        }
    }
}

void     print_di1(char a[21], int m[12])
{
    int i;

    i = 20;
    while (i >= 0)
    {
        if (a[i] != '.' )
        {
            write(1, &a[i], 1);
            m[11]++;
        }
        i--;
    }
}



int     fttoc1(char t[100], int j)
{
    int f;

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

void     print_d1(char a[21], int m[12])
{
    int i;

    i = 20;
    while (i >= 0)
    {
        if (a[i] != '.' )
        {
            write(1, &a[i], 1);
            m[11]++;
        }
        i--;
    }
}

int     fttoc(char t[100], float  n, int m[12])
{
    size_t k;
    int p;
    int j;

    j = 0;
    p = m[6];
    if (n < 0)
        n = n * (-1);
    k = (size_t)n;
    n = n - (float)(k);
    if((size_t)(n * 10) % 2 == 0)
    {
     if ((size_t)(n * 10) >= 5)
            m[10] = 1;
    }
    else 
        if ((size_t)(n * 10) > 5)
            m[10] = 1;
    while (p-- > 0 && j < 100)
    {
         n = n * 10;
         k = (size_t)(n);
         if (j == 0 && k >= 5)
            m[10] = 1;
         t[j++] = k + '0';
         n = n - (float)(k);  
    }
    if ((int)(n * 10) >= 5)
        m[8] = fttoc1(t, --j);
    return (0);
}

int     print_f(char t[100], int m[12], char a[21], float  n)
{
    if (m[0] == 0)
        if (m[4] == 1)
        {
            signf(n, m[1], m[2]);
            writeln(m[5] - m[6] - m[1] - m[2] - m[9] - 1, '0', m);
        }
        else
        {
            writeln(m[5] - m[6] - m[1] - m[2] - m[9] - 1, ' ', m);
            signf(n, m[1], m[2]);   
        }
    if (m[0] == 1)
        signf(n, m[1], m[2]);
    print_d1(a, m);
    if (m[6] != 0 || m[7] == 0 )
    {
    writeln(1, '.', m); 
    print_f1(t);
    }
    writeln(m[6] - 100, '0', m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[1] - m[2] - m[9] - 1, ' ', m);
}
int     type_f(va_list *vl, int m[12])
{
    float   n;
    long long int     k;
    char a[21];
    char t[100];

    if (m[6] == 0 && m[7] == 0)
        m[6] = 6;
    n = (float)(va_arg(*vl, double));
    di1(a);
    f1(t);
    //if (!(m[7] == 1 && m[6] == 0))
    fttoc(t, n, m);
    k = n;
    if (m[6] == 0 && m[7] == 1 && m[10] == 1)
        m[8]++;
        if (n < 0)
        m[8] = m[8] * (-1);
    m[9] = ftoc(a, k + m[8], m);
    print_f(t, m, a, n);

}

void     print_f1(char a[100])
{
    int i;

    i = 0;
    while (i < 100)
    {
        if (('0' <= a[i]) && (a[i] <= '9'))
            write(1, &a[i],1);
        i++;
    }
}

void signf(float n, int f1, int f2)
{
    if (n < 0 || n == -0)
        write(1, "-",1);
    else
    {
        if (f1 == 1)
            write(1, "+",1);
        if (f2 == 1)
            write(1, " ",1);
    } 
}

void    f1(char a[100])
{
    int i;

    i = 0;
    while (i <100)
        a[i++] = '.'; 
}

int    ftoc(char a[21], long long int n, int m[12])
{
    int k;
	int i;

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
    return k;
}

int     itoc(char a[21], int n, int m[12])
{
    int k;
    int i;
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
    while (n != 0)
    {
        if (n> 0)
        a[i++] = (n % 10) + '0';
        else
        a[i++] = ((n % 10)*(-1)) + '0';
        n = n / 10;
        k++;
    }
    if (k > m[6])
        m[6] = 0;
    return k;
}


int     print_di(char a[15], int m[8], int k, int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signdi(n, m[1], m[2], m);
            writeln(m[5] - m[6] - m[1] - m[2] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[1] - m[2] - k, ' ',m);
            signdi(n, m[1], m[2], m);
        }
    }
    if (m[0] == 1)
        signdi(n, m[1], m[2], m);
    writeln(m[6] - k - m[8], '0',m);
    print_di1(a,m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[1] - m[2] - k, ' ',m);
}
int     type_di(va_list *vl, int m[12])
{
    int n;
    int k;
    char a[21];
    n = va_arg(*vl, int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[10] = 1;
    di1(a);
    k = itoc(a, n, m);
    if (m[10] == 1)
        k  = 0;
    if (m[6] >= k)
    {
        m[8] = k;
        k = 0;
    }
    
    print_di(a, m, k, n);
    //write("%s",a);
    return (k);
}

int     distrib_types(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    type_f(vl, m);
    return (0);
}
int     accuracy(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    m[6] = 0;
    if (f[ii] == '.')
    {
        m[7] = 1;
        while ((48 <= f[++ii]) && (f[ii] <= 57))
            m[6] = (m[6] * 10) + (f[ii] - '0');
        if(f[ii] == '*')
        {
            m[6] = va_arg(*vl, int);
            ii++;
        }
    }
    *i = ii;
    return (distrib_types(i, f, m, vl));
}
int     width(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    while ((48 <= f[ii]) && (f[ii] <= 57))
        m[5] = (m[5] * 10) + (f[ii++] - '0');
    *i = ii;
    return (accuracy(i, f, m, vl));
}
int     flag(int *i, char *f, va_list *vl)
{
    int m[12];
    int ii;
    ii = *i;
    nol(m);
    while (flag1(f[ii]))
    {
        if (f[ii] == '-')
        {
            m[4] = 0;
            m[0] = 1;
        }
        if (f[ii] == '+')
            m[1] = 1;
        if (f[ii] == ' ' && m[1] != 1)
            m[2] = 1;
        if (f[ii] == '#')
            m[3] = 1;
        if (f[ii] == '0' && m[0] == 0)
            m[4] = 1;
        ii++;
    }
    if (m[1] == 1)
        m[2] = 0;
    *i = ii;
    width(i, f, m, vl);
    return (m[11]);
}


int ft_printf(char *flags, ...)
{
    int i;
    size_t ch;
    int b;
    int k;
    i = 0;
    k = 0;
    b = 0;
    va_list vl;
    va_start(vl, flags);
    while (flags[i] != '\0')
    {
        if (flags[i] != '\\' && flags[i] != '%') {
            write(1, &flags[i], 1);
            b++;
        }
        else if (flags[i] == '%')
        {
            
            i++;
            b = b + flag(&i, flags, &vl);
        }
         else if (flags[i] == '\\' )
        {
            write(1, "\\", 1);
            b++;
        }
        i++;
    }
    return (k+b);
}

int main()
{
float ar = 1234567890123456789123456.2828297323;
printf("%.0f", 5.5);
ft_printf("%.0f", 5.5);

}