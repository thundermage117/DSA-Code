#include "Polynomial.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Poly InitPoly()
{
    PtrToTerm P = (PtrToTerm)malloc(sizeof(PolyTerm));   
    assert(P!=NULL);

    P->coeff = -1;
    P->Next = NULL;

    return P;
}

void AddTerm(Poly P,unsigned int expo,double coeff)
{
    
    PtrToTerm T;

    while(P->Next && P->Next->expo < expo)
    {
        //T = P->Next;
        P = P->Next;
    }
    if(P->Next == NULL || P->Next->expo > expo)
    {
        T = InitPoly();
        T->expo = expo;
        T->coeff = coeff;
        T->Next = P->Next;
        P->Next = T;        
    }
    else if(P->Next->expo == expo)
    {
        T=InitPoly();
        T->expo=expo;
        T->coeff=P->Next->coeff+coeff;
        T->Next = P->Next->Next;
        P->Next = T;  
        if(T->coeff==0)// to remove 0 from poly
            DeleteTermByExponent(P,T->expo);
    }
    
    else
    {
        P->Next->coeff = coeff;
    }    
}

void DeleteTermByExponent(Poly P,unsigned int expo)
{
    PtrToTerm Prev=P;
   
    while(P->Next && P->Next->expo < expo)
    {
        Prev = P->Next;
        P = P->Next;
    }

    if(P->Next == NULL || P->Next->expo > expo)
    {
       printf("ERROR: No polynomial term with exponent %d to delete\n",expo);     
    }
    else
    {
        Prev = P->Next;
        P->Next = P->Next->Next;
        free(Prev);
    }
    printf("Done\n");

}

void PrintPoly(Poly P)
{
    if(!P)
    {
        printf("Polynomial Does Not Exist\n");
        return;
    }
    P=P->Next;
    if(!P)
    {
        printf("0\n");
        return;
    }
    if(P->expo==0)
    {    
        printf("%g",P->coeff);
        P=P->Next;
    }
    while(P)
    {   
        if(P->coeff>0)
            printf("%+gx^%d",P->coeff,P->expo);
        else
            printf("%gx^%d",P->coeff,P->expo);
        P=P->Next;
    }
    printf("\n\n");  
}

void DeleteAllTerms(Poly P)
{
    Poly tmp=P;
    tmp=tmp->Next;
    PtrToTerm  Curr;
    while( tmp != NULL )
    {
        Curr = tmp;
        tmp = tmp->Next;
        if(!Curr)
            free(Curr);
    }
    P->Next=NULL;
    printf("Done\n");

}

void DeletePoly(Poly *P)
{
    DeleteAllTerms(*P);
    free(*P);
    *P=NULL;
}
Poly copyList(Poly term) 
{ 
    if (term == NULL) 
        return NULL; 
    else 
    {
        Poly newNode = (Poly)malloc( sizeof(PolyTerm)); 
  
        newNode->coeff = term->coeff; 
        newNode->expo = term->expo;
  
        
        newNode->Next = copyList(term->Next); 
  
        return newNode; 
    } 
}



void AddPolynomials(Poly A, Poly B, Poly *C)
{   DeleteAllTerms(*C);
    *C=copyList(A);
    B=B->Next;
    // *C=(*C)->Next;
    while(B)
    {
        AddTerm(*C,B->expo,B->coeff);
        B=B->Next;
    }



}

void SubtractPolynomials(Poly A,Poly B, Poly *C)
{   DeleteAllTerms(*C);
    *C=copyList(A);
    B=B->Next;
    // *C=(*C)->Next;
    while(B)
    {
        AddTerm(*C,B->expo,((-1)*(B->coeff)));
        B=B->Next;
    }
}

void GetMiddle(Poly P)
{
    Poly A=P,B=P;
    if(P!=NULL)
    {
        while(B!=NULL&&(B->Next)!=NULL)
        {
            B=B->Next->Next;
            A=A->Next;
        }
        printf("Middle term coeff: %f",A->coeff);   
    }


}