 int     type_xX(va_list *vl, int m[12])
{
    int n;
    int k;
    char a[21];

    n = va_arg(*vl, int);
    di1(a);
    k = xtoc(a, n, m);
    if (m[3] == 1)
        m[3] = 2;
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }
    print_x(a, m, k, n);
    //printf("%s",a);
    return (0);
}

void    signx(int f, int f1)
{
    if (f == 2)
    {
        printf("%c", '0');
        if (f1 == 2)
            printf("%c", 'X');
        else
            printf("%c", 'x'); 
    }
    if (f == 1)
        printf("%c", '0');
}

int     print_x(char a[15], int m[8], int k, int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signx(m[3], m[10]);
            writeln(m[5] - m[6] - m[3] - k, '0');
        }
        else
        {
            writeln(m[5] - m[6] - m[3] - k, ' ');
            signx(m[3], m[10]);
        }
    }
    if (m[0] == 1)
        signx(m[3], m[10]);
    writeln(m[6] - k - m[8], '0');
    print_di1(a);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[3] - k, ' ');
}

int     xtoc(char a[21], int n, int m[12])
{
    int k;
    int i;

    k = 0;
    i = 0;
    if (n < 0)
    {
        n = n * (-1);
    }
    if (n == 0)
    {
        k++;
        a[i] = '0';
    }
    while (n > 0)
    {
        a[i++] = xX(n % 16, m[10]);
        n = n / 16;
        k++;
    }
    if (k > m[6])
        m[6] = 0;
    return k;
}

int     flag1(char c)
{
    if (c == '-' || c == ' ' || c == '+' || c == '#' || c == '0')
        return (1);
    return (0);
}


char xX(int n, int f)
{
    char c;

    c = n + '0';
    if (n > 9)
    {
        if (n == 10)
            c = 'a';
        else if (n == 11)
            c = 'b';
        else if (n == 12)
            c = 'c';
        else if (n == 13)
            c = 'd';
        else if (n == 14)
            c = 'e';
        else if (n == 15)
            c = 'f';
        if (f  == 2)
            return (c - 32);
        else
            return (c);
    }
    return (c);
}







































else if (f[ii] == '%')
        printf ("%c", '%');
    else if (f[ii] != '\0')
        printf ("%c", f[ii]);


























#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int     flag1(char c)
{
    if (c == '-' || c == ' ' || c == '+' || c == '#' || c == '0')
        return (1);
    return (0);
}

void writeln(int n, char c)
{
    while (n-- > 0)
        write(1, &c, 1);
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


void signdi(int n, int f1, int f2)
{
    if (n < 0 )
        write(1, "-", 1);
    else
    {
        if (f1 == 1)
            write(1, "+", 1);
        if (f2 == 1)
            write(1, " ", 1);
    }
}

void     print_di1(char a[21])
{
    int i;

    i = 20;
    while (i >= 0)
    {
        if (a[i] != '.')
            write("1, &a[i], 1);
        i--;
    }
}

int     print_di(char a[15], int m[8], int k, int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signdi(n, m[1], m[2]);
            writeln(m[5] - m[6] - m[1] - m[2] - k, '0');
        }
        else
        {
            writeln(m[5] - m[6] - m[1] - m[2] - k, ' ');
            signdi(n, m[1], m[2]);
        }
    }
    if (m[0] == 1)
        signdi(n, m[1], m[2]);
    writeln(m[6] - k - m[8], '0');
    print_di1(a);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[1] - m[2] - k, ' ');
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
    while (n > 0)
    {
        a[i++] = (n % 10) + '0';
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

int     distrib_types(int *i, char *f, int m[12], va_list *vl)
{
    int ii;

    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_di(vl, m));
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
    *i = ii;

    return width(i, f, m, vl);
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
            k = k + flag(&i, flags, &vl);
        }
        i++;
    }
    return (k+b);
}

int main()
{
    int a = 10900;
    int v, v1;

    v = printf ("%d\n", a);
    v1 = printff("%d\n", a);
    printf ("%d\n", v);
    printf ("%d\n", v1);

    return 0;
}
