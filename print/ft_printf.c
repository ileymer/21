#include "printlib.h"

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
        if(f[ii] == '*')
        {
            m[6] = va_arg(*vl, int);
            ii++;
        }
        if (m[6] < 0)
        {
            m[7] = 0;
            m[6] = 0;
        }
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
        if(f[ii] == '*')
        {
            m[5] = va_arg(*vl, int);
            if (m[5] < 0)
            {
                m[5] = m[5] * (-1);
                m[0] = 1;
            }
            ii++;
        }
    *i = ii;
    return (accuracy(i, f, m, vl));
}
int     flag(int *i, char *f, va_list *vl)
{
    int m[13];
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



int main()
{
    printf("%#\n");
    ft_printf("%#");
    
}




