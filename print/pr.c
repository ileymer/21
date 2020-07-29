#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>



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
        if (a[i] != '.' && (m[10] != 1))
        {
            write(1, &a[i], 1);
            m[11]++;
        }
        i--;
    }
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
            writeln(m[5] - m[6] - m[1] - m[2] - k+m[10], ' ',m);
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
    if (m[6] >= k)
    {
        m[8] = k;
        k = 0;
    }
    print_di(a, m, k, n);
    //write("%s",a);
    return (k);
}


int     litoc(char a[21], long int n, int m[12])
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
int     type_ldi(va_list *vl, int m[12])
{
    long int n;
    int k;
    char a[21];
    n = va_arg(*vl, long int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[10] = 1;
    di1(a);
    k = litoc(a, n, m);
    if (m[6] >= k)
    {
        m[8] = k;
        k = 0;
    }
    print_di(a, m, k, n);
    //write("%s",a);
    return (k);
}
int     distrib_l(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_ldi(vl, m));
    return(0);
}
int     distrib_types(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_di(vl, m));
    else if (f[ii] == '%')
    {
        write(1, "%", 1);
        m[11]++;
    }
    else if (f[ii] == 'l' )
    {
        ii++;
        *i = ii;
        return (distrib_l(i, f, m, vl));
    }
    else if (f[ii] != '\0')
    {
        write(1, &f[ii], 1);
        m[11]++;
    }
/*    if (f[ii] == 's')
        type_s(vl, m);
    if (f[ii] == 'd' || f[ii] == 'i')
        type_di(vl, m);
    if (f[ii] == 'f')
        type_f(vl, m);
    if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_xX(vl, m);
    }
    if (f[ii] == 'o')
        type_o(vl, m);
    if (f[ii] == 'c')
        type_c(vl, m);*/
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
        else
        {
            i++;
            b = b + flag(&i, flags, &vl);
        }
        i++;
    }
    return (k+b);
}

int main()
{
    int a = 21;
    int v, v1;
    char d = a;
    
    printf ("%ld", 2147483699);
    printf ("\n");
    ft_printf ("%ld", 2147483648);
    printf ("\n");
    return 0;
}
