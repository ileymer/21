#include "printlib.h"

int     llitoc(char a[21], long long int n, int m[12])
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
int     type_lldi(va_list *vl, int m[12])
{
    long long int n;
    int k;
    char a[21];
    n = va_arg(*vl, long long int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[10] = 1;
    di1(a);
    k = llitoc(a, n, m);
    if (m[6] >= k)
    {
        m[8] = k;
        k = 0;
    }
    print_lldi(a, m, k, n);
    //write("%s",a);
    return (k);
}

int     print_lldi(char a[15], int m[8], int k, long long int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signlldi(n, m[1], m[2], m);
            writeln(m[5] - m[6] - m[1] - m[2] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[1] - m[2] - k+m[10], ' ',m);
            signlldi(n, m[1], m[2], m);
        }
    }
    if (m[0] == 1)
        signlldi(n, m[1], m[2], m);
    writeln(m[6] - k - m[8], '0',m);
    print_di1(a,m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[1] - m[2] - k, ' ',m);
}

void signlldi(long long int n, int f1, int f2,int m[12])
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