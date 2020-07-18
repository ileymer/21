#ifndef PRINTLIB_H
# define PRINTLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>



int     flag1(char c);
void writeln(int n, char c, int m[12]);
void nol(int m[12]);
void    di1(char a[21]);
void signdi(int n, int f1, int f2,int m[12]);
void     print_di1(char a[21], int m[12]);
int     print_di(char a[15], int m[8], int k, int n);
int     itoc(char a[21], int n, int m[12]);
int     type_di(va_list *vl, int m[12]);
int     distrib_types(int *i, char *f, int m[12], va_list *vl);
int     accuracy(int *i, char *f, int m[12], va_list *vl);
int     width(int *i, char *f, int m[12], va_list *vl);
int     flag(int *i, char *f, va_list *vl);
int ft_printf(char *flags, ...);
int     litoc(char a[21], long int n, int m[12]);
int     type_ldi(va_list *vl, int m[12]);
int     distrib_l(int *i, char *f, int m[12], va_list *vl);
int     distrib_ll(int *i, char *f, int m[12], va_list *vl);
int     print_ldi(char a[15], int m[8], int k, long int n);
void signldi(long int n, int f1, int f2,int m[12]);
int     llitoc(char a[21], long long int n, int m[12]);
int     type_lldi(va_list *vl, int m[12]);
int     print_lldi(char a[15], int m[8], int k, long long int n);
void signlldi(long long int n, int f1, int f2,int m[12]);
int     hitoc(char a[21], short int n, int m[12]);
int     type_hdi(va_list *vl, int m[12]);
int     print_hdi(char a[15], int m[8], int k, short int n);
void signhdi(short int n, int f1, int f2,int m[12]);
int     distrib_h(int *i, char *f, int m[12], va_list *vl);
int     type_xX(va_list *vl, int m[12]);
void    signx(int f, int f1, int m[12], unsigned int n);
int     print_x(char a[15], int m[8], int k, unsigned int n);
int     xtoc(char a[21], unsigned int n, int m[12]);
char xX(unsigned int n, int f);
char minusxX(int n, int f,int i, int m[12]);
int fxX(char a[21], int f);
void     print_x1(char a[21], int m[12]);
int     type_lxX(va_list *vl, int m[12]);
void    signlx(int f, int f1, int m[12], long int n);
int     print_lx(char a[15], int m[8], int k, long int n);
int     lxtoc(char a[21], long int n, int m[12]);
char minuslxX(long int n, int f,int i, int m[12]);
int lfxX(char a[21], int f);
char lxX(long int n, int f);
int     type_llxX(va_list *vl, int m[12]);
void    signllx(int f, int f1, int m[12], long long int n);
int     print_llx(char a[15], int m[8], int k, long long int n);
int     llxtoc(char a[21], long long int n, int m[12]);
char minusllxX(long long int n, int f,int i, int m[12]);
char llxX(long long int n, int f);
int     type_hxX(va_list *vl, int m[12]);
void    signhx(int f, int f1, int m[12], short int n);
int     print_hx(char a[15], int m[8], int k, short int n);
int     hxtoc(char a[21], short int n, int m[12]);
char    minushxX(short int n, int f,int i, int m[12]);
int     hfxX(char a[21], int f);
char    hxX(short int n, int f);
int     type_o(va_list *vl, int m[12]);

int     otoc(char a[21], unsigned int n, int m[12]);
int     print_c(int m[12], char n);
int     type_c(va_list *vl, int m[12]);
void writes(char *s, int m[12]);
int     print_s(int m[8], char *n);
int     type_s(va_list *vl, int m[12]);

void    nulls(int m[12]);

int     hhitoc(char a[21], signed char n, int m[12]);
int     type_hhdi(va_list *vl, int m[12]);
int     print_hhdi(char a[15], int m[8], int k, signed char n);
void signhhdi(signed char n, int f1, int f2,int m[12]);
int     type_hhxX(va_list *vl, int m[12]);
void    signhhx(int f, int f1, int m[12], signed char n);
int     print_hhx(char a[15], int m[8], int k, signed char n);
int     hhxtoc(char a[21], signed char n, int m[12]);
char minushhxX(signed char n, int f,int i, int m[12]);
int hhfxX(char a[21], int f);
char hhxX(signed char  n, int f);
int     utoc(char a[21], unsigned int n, int m[12]);
int     type_u(va_list *vl, int m[12]);
int     print_u(char a[15], int m[8], int k, unsigned int n);
void signu(unsigned int n, int f1, int f2,int m[12]);
int     type_p(va_list *vl, int m[12]);

#endif