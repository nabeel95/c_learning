#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"


int main(void){
	int a=15;
	void *first=&a;
	int b=45;
	void *second=&b;
	int c=14;
	void *third=&c;
	ArrayUtil arr1 = create(4,4);
	ArrayUtil arr2 = create(4,4);
	ArrayUtil arr3 = create(4,4);
	*(arr1.base)   = 2;
	*(arr1.base+1) = 45;
	*(arr1.base+2) = 6;	
	*(arr1.base+3) = 8;

	*(arr3.base)   = 15;
	*(arr3.base+1) = 1;
	*(arr3.base+2) = 2;
	*(arr3.base+3) = 3;

	// int *res = findFirst(arr1, isEven, NULL);
	// printf("find first isEven %d\n",*res );
	printf("find first isDivisible %d\n",*((int *)findFirst(arr1, isDivisible, first)));
	printf("find last isDivisible %d\n",*((int *)findLast(arr1, isDivisible, first)));
	// printf("count of isDivisible %d\n",count(arr1, isDivisible, first) );
	// printf("count of isEven %d\n",count(arr1, isEven, first) );

	// int maxItems = 4;
	// ArrayUtil destination = create(sizeof(int),maxItems);
	// void* dest = &destination;
	// int result = filter(arr1,isEven,first,&dest,maxItems);
	// printf("%d\n",result );
	// printf("%d\n",destination.base[0] ); 
	// printf("%d\n",destination.base[1] );
	// printf("%d\n",destination.base[2] );
	// printf("%d\n",destination.base[3] );

	
	return 0;
};