#include "printlib.h"



void    type_b(va_list *vl, int m[12], int o)
{
    unsigned int n;
    int k;
    char a[50];
    n = (unsigned int)va_arg(*vl, int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[10] = 1;
    b_mas(a);
    
    bon_toc(a,n,m,o);
    if (m[6] >= k)
    {
        m[8] = k;
        k = 0;
    }
    if (m[10] == 1)
        k  = 0;
    print_bon(a,m,k,n);
}



void    b_mas(char a[50])
{
    int i;

    i = 0;
    while (i < 50)
        a[i++] = '.';
}

int     bon_toc(char a[50], unsigned int n, int m[12], int o)
{
    int k;
    int i;
    k = 0;
    i = 0;

    if (n == 0)
    {
        k++;
        a[i] = '0';
    }
    while (n > 0)
    {
        a[i++] = paste_x(n % o, m[10]);
        n = n / o;
        k++;
    }
    if (k > m[6])
        m[6] = 0;
    return k;
}

int     print_bon(char a[50], int m[8], int k, unsigned int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            writeln(m[5] - m[6] - m[1] - m[2] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[1] - m[2] - k, ' ',m);
        }
    }
    
    writeln(m[6] - k - m[8], '0',m);
    print_bon1(a,m); 
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[1] - m[2] - k, ' ',m);
}

void     print_bon1(char a[50], int m[12])
{
    int i;

    i = 49;
    while (i >= 0)
    {
        if (a[i] != '.' && m[10] != 1)
        {
            write(1, &a[i], 1);
            m[11]++;
        }
        i--;
    }
}

int bon_flag(char c)
{
    if (c == 'b')
        return (2);
    else if (c == 'c')
        return (3);  
    else if (c == 'd')
        return (4); 
    else if (c == 'e')
        return (5);
    else if (c == 'f')
        return (6);
    else if (c == 'g')
        return (7);
    else if (c == 'h')
        return (8);
    else if (c == 'i')
        return (9);
    else if (c == 'j')
        return (10);
    else if (c == 'k')
        return (11);
    else if (c == 'l')
        return (12);
    else if (c == 'm')
        return (13);
    return (0);
}

int     distrib_b(int *i, char *f, int m[12], va_list *vl)
{
    int o;
    int ii;

    ii = *i;
    o = bon_flag(f[ii]);
    if (f[ii] == 'n')
        o = 14;
    else if (f[ii] == 'o')
        o = 15;
    else if (f[ii] == 'p')
        o = 16;
    if (o != 0)
        type_b(vl,m,o);
}