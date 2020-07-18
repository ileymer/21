#include "printlib.h"


int     distrib_ll(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_ldi(vl, m));
    else if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_llxX(vl, m);
    }
}

int     distrib_l(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_ldi(vl, m));
    if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_lxX(vl, m);
    }
    else if (f[ii] == 'l' )
    {
        ii++;
        *i = ii;
        return (distrib_ll(i, f, m, vl));
    }
    return(0);
}

int     distrib_hh(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_hhdi(vl, m));
    else if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_hhxX(vl, m);
    }
   
    
  /*  else if (f[ii] == 'l' )
    {
        ii++;
        *i = ii;
        return (distrib_ll(i, f, m, vl));
    }*/
    return(0);
}



int     distrib_h(int *i, char *f, int m[12], va_list *vl)
{
    int ii;
    ii = *i;
    if (f[ii] == 'd' || f[ii] == 'i')
        return(type_hdi(vl, m));
    else if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_hxX(vl, m);
    }
        else if (f[ii] == 'h' )
    {
        ii++;
        *i = ii;
        return (distrib_hh(i, f, m, vl));
    }
    
  /*  else if (f[ii] == 'l' )
    {
        ii++;
        *i = ii;
        return (distrib_ll(i, f, m, vl));
    }*/
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
    else if (f[ii] == 'h' )
    {
        ii++;
        *i = ii;
        return (distrib_h(i, f, m, vl));
    }
    else if (f[ii] == 'x' || f[ii] == 'X')
    {
        if (f[ii] == 'X')
            m[10] = 2;
        type_xX(vl, m);
    }
    else if (f[ii] == 'o')
        type_o(vl, m);
     else if (f[ii] == 'u')
        type_u(vl, m);    
    else if (f[ii] == 'c')
        type_c(vl, m);
    else if (f[ii] == 's')
        type_s(vl, m);
    else if (f[ii] == 'p')
        type_p(vl, m);
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
        else if (flags[i] == '%')
        {
            
            i++;
            b = b + flag(&i, flags, &vl);
        }
         else if (flags[i] == '\\' )
        {
            write(1, "\\", 1);
            b++;
        }
        i++;
    }
    return (k+b);
}

int mainwe (unsigned int a)
{
    printf ("%u", a);
}


int main()
{
    int a = 300000;
    char *l ;
    char k;
    k = -22;
    l = &k;
    int v ,v1 ;
    unsigned long int dd;
    dd = (unsigned long int)(void*)k;
    v = printf("%p", k);  
    printf("\n%i\n",v);
    v1 = ft_printf("%p", k); 
    printf("\n%i\n", v1);
}