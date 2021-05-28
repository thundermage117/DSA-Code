#ifndef __POLYNOMIAL_1
#define __POLYNOMIAL_1

#include "PolyElem.h"

Poly InitPoly();

void AddTerm(Poly P,unsigned int expo,double coeff);
void DeleteTermByExponent(Poly P,unsigned int expo);

void AddPolynomials(Poly A,Poly B,Poly *C);
void SubtractPolynomials(Poly A,Poly B, Poly *C);

Poly copyList(Poly term); 

void DeleteAllTerms(Poly P);
void DeletePoly(Poly *P);

void GetMiddle(Poly P);

void PrintPoly(Poly P);
#endif