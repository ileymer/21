#include "printlib.h"
 
int     type_llxX(va_list *vl, int m[12])
{
    long long int n;
    int k;
    char a[21];

    m[1] = 0;
    
    n = va_arg(*vl, long long int);
    if (n == 0 && m[6] == 0 && m[7] == 1)
    m[1] = 1;
    di1(a);
    k = llxtoc(a, n, m);
    if (m[3] == 1)
        m[3] = 2;
    if (m[6] >= k)
    {
        m[8] = k;;
        k = 0;
    }
    print_llx(a, m, k, n);
    //printf("%s",a);
    return (0);
}

void    signllx(int f, int f1, int m[12], long long int n)
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





int     print_llx(char a[15], int m[8], int k, long long int n)
{
    if (m[0] == 0)
    {
        if (m[4] == 1 && m[7] == 0)
        {
            signllx(m[3], m[10],m,n);
            writeln(m[5] - m[6] - m[3] - k, '0',m);
        }
        else
        {
            writeln(m[5] - m[6] - m[3] - k +m[1], ' ',m);
            signllx(m[3], m[10],m,n);
        }
    }
    if (m[0] == 1)
        signllx(m[3], m[10],m,n);
    writeln(m[6] - k - m[8], '0',m);
    print_x1(a,m);
    if (m[0] == 1)
        writeln(m[5] - m[6] - m[3] - k, ' ',m);
}

int     llxtoc(char a[21], long long int n, int m[12])
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
        a[i++] = llxX(n % 16, m[10]);
        n = n / 16;
        k++;
    }
    else
    {
        while (n != 0)
        {
        a[i] = minusllxX(n % 16, m[10],i,m);
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


char minusllxX(long long int n, int f,int i, int m[12])
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
    return llxX(n, f);
}












char llxX(long long int n, int f)
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