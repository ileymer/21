#include "printlib.h"
 
int     type_o(va_list *vl, int m[12])
{
    int n;
    int k;
    char a[21];

    m[1] = 0;
    
    n = va_arg(*vl, unsigned int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[1] = 1;
    di1(a);
    k = otoc(a, n, m);
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }   
    print_x(a, m, k, n);
    //printf("%s",a);
    return (0);
}








int     otoc(char a[21], unsigned int n, int m[12])
{
    int k;
    int i;

    k = 0;
    i = 0;
    if (n < 0)
    {
        n = n * (-1);
        m[9] = 1;
    }
    if (n == 0)
    {
        k++;
        a[i] = '0';
    }
   
    while (n > 0)
    {
        a[i++] = (n % 8) + '0';
        n = n / 8;
        k++;
    }
   
    
    if (k > m[6])
        m[6] = 0;
    return k;
}





