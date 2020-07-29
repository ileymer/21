#include "printlib.h"

int check_dioux(char c)
{
    if (c == 'd' || c == 'i' || c == 'o' || c == 'u'  || c == 'x' || c == 'X')
        return (1);
    return (0);
}

int check_csp(char c)
{
    if (c == 'c' || c == 's' || c == 'p')
        return (1);
    return (0);
}

int check_hlb(char c)
{
    if (c == 'l' || c == 'h' || c == 'L' || c == 'b')
        return (1);
    return (0);
}