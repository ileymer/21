#include "printlib.h"

int dioux(va_list *vl, int m[12], char f)
{
    if (f == 'd' || f == 'i')
        return(type_di(vl, m));
    else if (f == 'o')
        return(type_o(vl, m));
    else if (f == 'u')
        return(type_u(vl, m)); 
    else if (f == 'x' || f == 'X')
    {
        if (f == 'X')
            m[10] = 2;
        return(type_x(vl, m));
    }
}







int csp(va_list *vl, int m[12], char f)
{
    if (f == 'c')
        return(type_c(vl, m));
    else if (f == 's')
        return(type_s(vl, m));
    else if (f == 'p')
        return(type_p(vl, m)); 
    return (0);
}




int hlb(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;

    if(f[ii] == 'b')
    {
        ii++;
        *i = ii;
        return (distrib_b(i, f, m, vl));
    }
    else if (f[ii] == 'l' )
    {
        ii++;
        *i = ii;
        return (distrib_l(i, f, m, vl));
    }
    else if (f[ii] == 'h' )
    {
        ii++;
        *i = ii;
        return (distrib_h(i, f, m, vl));
    }
    return (0);
}