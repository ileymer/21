
#include "printlib.h"

void nulls(int m[12])
{
    if (m[7] != 1 || m[6] > 5)
    {
        write(1, "(null)", 6);
        m[11] = m[11] + 6;
    }
}
void writes(char *s, int m[12])
{
    int i;

    i =0;
    if(m[6] != 0 || m[7] == 1)
    while (s[i] != '\0' && i < m[6])
    {
        write (1, &s[i], 1);
        m[11]++;
        i++;
    }
    else
    {
        while (s[i] != '\0' )
        {
            write (1, &s[i], 1);
            m[11]++;
            i++;
        }
    }
    
}

int     print_s(int m[8], char *n)
{
    if (n != NULL)
    {
    if (m[0] == 0)
    {
        if (m[4] == 1)
        {   
            if (m[6] < m[5] && m[6] < strlen(n))
            writeln(m[5] +m[6]- strlen(n), '0', m);
            else
            writeln(m[5] - strlen(n), '0', m);
        }
        else 
        {
            if (m[6] < m[5] && m[6] < strlen(n))
            writeln(m[5] +m[6]- strlen(n), ' ', m);
            else
            writeln(m[5] - strlen(n), ' ', m);
            }
           

    }
    writes(n,m);
    if (m[0] == 1)
        {
            if (m[6] < m[5] && m[6] < strlen(n))
            writeln(m[5] +m[6]- strlen(n), ' ', m);
            else
            writeln(m[5] - strlen(n), ' ', m);
        }
    }
    else
    nulls(m);
    return 0;
}


int     type_s(va_list *vl, int m[12])
{
    char *n;

    n = va_arg(*vl, char *);
    print_s(m, n);
    //printf("%s",a);
    return (0);
}