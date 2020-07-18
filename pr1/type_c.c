#include "printlib.h"



 int     print_c(int m[12], char n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1)
            writeln(m[5] - 1, '0', m);
        else 
            writeln(m[5] - 1, ' ', m);
    }
    writeln(1 , n, m);
    if (m[0] == 1)
        writeln(m[5] - 1, ' ', m);
    return 0;
}

int     type_c(va_list *vl, int m[12])
{
    char n;

    n = va_arg(*vl, int);
    print_c(m, n);
    //printf("%s",a);
    return (0);
}