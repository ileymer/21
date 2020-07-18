#include "printlib.h"




int     type_p(va_list *vl, int m[12])
{
    unsigned long int n;
    char a[21];
    int k;

    n = (unsigned long int)(void*)va_arg(*vl, unsigned long int);
    m[10] = 1;
    m[3] = 2;
    di1(a);
    k = lxtoc(a, n, m);
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }
    print_lx(a, m, k, n);
    return (0);
}