#include "SinglyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	List L=NULL;
	PtrToNode P;

	// This doesn't work as intended !
	//CreateEmptyList2(L);
	//assert(L != NULL);

	// Use one of the following 	
	CreateEmptyList1(&L);
	// or
	//L = CreateEmptyList();

	// Insert item at front of list	
	/* InsertAtFront(&L,10);
	InsertAtFront(&L,20);
	InsertAtFront(&L,30); */
    
    //insert at rear not implemented 
    InsertAtFront_v2(L,2);
	InsertAtFront_v2(L,4);
	InsertAtFront_v2(L,3);
    InsertAtFront_v2(L,2);
    InsertAtFront_v2(L,1);
    PrintList(L);
    printf("%d\n",FindLast(L,2));
    DeleteAll(L,2);
    PrintList(L);

	//DeleteList(&L);
	
	return 0;
}
