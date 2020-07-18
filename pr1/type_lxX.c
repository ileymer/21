#include "printlib.h"
 
int     type_lxX(va_list *vl, int m[12])
{
    long int n;
    int k;
    char a[21];

    m[1] = 0;
    
    n = va_arg(*vl, long int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[1] = 1;
    di1(a);
    k = lxtoc(a, n, m);
    if (m[3] == 1)
        m[3] = 2;
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }
    print_lx(a, m, k, n);
    //printf("%s",a);
    return (0);
}

void    signlx(int f, int f1, int m[12], long int n)
{
    if ( n !=0)
    if (f == 2)
    {
        write(1, "0", 1);
        m[11]++;
        if (f1 == 2)
        {
            write(1, "X", 1);
            m[11]++;
        }
        else
        {
            write(1, "x", 1);
            m[11]++;
        }
    }
    if (f == 1)
    {
        write(1, "0", 1);
        m[11]++;
    }
}





int     print_lx(char a[15], int m[8], int k, long int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signlx(m[3], m[10],m,n);
            writeln(m[5] - m[6] - m[3] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[3] - k +m[1], ' ',m);
            signlx(m[3], m[10],m,n);
        }
    }
    if (m[0] == 1)
        signlx(m[3], m[10],m,n);
    writeln(m[6] - k - m[8], '0',m);
    print_x1(a,m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[3] - k, ' ',m);
}

int     lxtoc(char a[21], long int n, int m[12])
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
    if(m[9] == 0)
    while (n > 0)
    {
        a[i++] = lxX(n % 16, m[10]);
        n = n / 16;
        k++;
    }
    else
    {
        while (n != 0)
        {
        a[i] = minuslxX(n % 16, m[10],i,m);
        i++;
        n = n / 16;
        k++;
        }
        lfxX(a, m[10]);
    }
    
    if (k > m[6])
        m[6] = 0;
    return k;
}


char minuslxX(long int n, int f,int i, int m[12])
{
    char c;
    //printf("\n--%d--\n", n);  
    if(n<0)
        n = n * (-1);
    n = 15 - n;
    
    if (i == 0)
     n++;
    if (m[9] == 16)
        n++;
    if (n == 16)
    {
        m[9] = n;
        n = 0;
    }
    return lxX(n, f);
}


int lfxX(char a[21], int f)
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (a[i] == '.')
        {
            if (f == 2)
                a[i] = 'F';
            else
                a[i] = 'f';        
        }
        i++;    
    }
}









char lxX(long int n, int f)
{
    char c;
    
    c = n + '0';
    if (n > 9)
    {
        if (n == 10)
            c = 'a';
        else if (n == 11)
            c = 'b';
        else if (n == 12)
            c = 'c';
        else if (n == 13)
            c = 'd';
        else if (n == 14)
            c = 'e';
        else if (n == 15)
            c = 'f';
        
        if (f  == 2)
            return (c - 32);
        else
            return (c);
    }
    return (c);
}