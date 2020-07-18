#include "printlib.h"

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