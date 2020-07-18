#include "printlib.h"
 
int     type_xX(va_list *vl, int m[12])
{
    int n;
    int k;
    char a[21];

    m[1] = 0;
    
    n = (unsigned int)va_arg(*vl, int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[1] = 1;
    di1(a);
    k = xtoc(a, n, m);
    if (m[3] == 1)
        m[3] = 2;
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }
    print_x(a, m, k, n);
    //printf("%s",a);
    return (0);
}

void    signx(int f, int f1, int m[12], unsigned int n)
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


void     print_x1(char a[21], int m[12])
{
    int i;

    i = 20;
    while (i >= 0)
    {
        if (a[i] != '.' && (m[1] != 1))
        {
            write(1, &a[i], 1);
            m[11]++;
        }
        i--;
    }
}


int     print_x(char a[15], int m[8], int k, unsigned int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signx(m[3], m[10],m,n);
            writeln(m[5] - m[6] - m[3] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[3] - k +m[1], ' ',m);
            signx(m[3], m[10],m,n);
        }
    }
    if (m[0] == 1)
        signx(m[3], m[10],m,n);
    writeln(m[6] - k - m[8], '0',m);
    print_x1(a,m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[3] - k, ' ',m);
}

int     xtoc(char a[21], unsigned int n, int m[12])
{
    int k;
    int i;

    k = 0;
    i = 0;
    if (n == 0)
    {
        k++;
        a[i] = '0';
    }
    if(m[9] == 0)
    while (n > 0)
    {
        a[i++] = xX(n % 16, m[10]);
        n = n / 16;
        k++;
    }

    if (k > m[6])
        m[6] = 0;
    return k;
}


char minusxX(int n, int f,int i, int m[12])
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
    return xX(n, f);
}


int fxX(char a[21], int f)
{
    int i;

    i = 0;
    while (i < 8)
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









char xX(unsigned int n, int f)
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