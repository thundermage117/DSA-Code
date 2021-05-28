#include "Polynomial.h"
#include <stdlib.h>

int main()
{
    Poly A,B,C;
    A = InitPoly();
    B = InitPoly();
    C=InitPoly();
    
    AddTerm(A,4,5);
    AddTerm(A,3,4);
    AddTerm(A,1,2);
    AddTerm(A,0,7);

    AddTerm(B,3,-7.2);
    AddTerm(B,2,4);
    AddTerm(B,0,-4);

    PrintPoly(A);
    PrintPoly(B);
    AddPolynomials(A,B,&C);
    PrintPoly(C);
    SubtractPolynomials(A,B,&C);
    PrintPoly(C);
    GetMiddle(C);

    
    // DeleteTermByExponent(B,3);
    // DeleteAllTerms(B);
    // PrintPoly(B);

    // DeletePoly(&B);
    // PrintPoly(B);

    return 0;
}