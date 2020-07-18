#include "printlib.h"

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