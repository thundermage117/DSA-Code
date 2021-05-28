#ifndef __COMP_H
#define __COMP_H


typedef int* complex;
typedef long long int big_no;

complex createcomp(int);

complex ADD(int, complex, complex);
complex SUB(int, complex, complex);
double MOD(int, complex);
big_no DOT(int, complex, complex);

void printcomp(int, complex);



#endif

