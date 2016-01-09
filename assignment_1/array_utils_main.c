#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"
int isEven(void* hint, void* item){
	return (*(int *)item%2)==0;
};

int isDivisible(void* hint, void* item){
	return (*(int *)item % *(int *)hint ==0);
};

int increment_1(void* hint, void* sourceItem, void* destinationItem){
	*(int *)destinationItem =(*(int *) sourceItem)+1;
	return 0;
	// return *(int *)destinationItem;
};

void increment1(void* hint, void* item){
	*(int *)item = *((int *)item)+1;
};
void *sum (void *hint, void *previousItem, void *item){
  int *result = malloc(sizeof(item));
  *result = *((int *)previousItem)+ *((int *)item);
  return result;
};

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
	*(arr1.base)   = 1;
	*(arr1.base+1) = 2;
	*(arr1.base+2) = 1;	
	*(arr1.base+3) = 2;

	*(arr3.base)   = 15;
	*(arr3.base+1) = 1;
	*(arr3.base+2) = 2;
	*(arr3.base+3) = 3;

	int name = *((int *)reduce(arr1, sum, first, third));
	printf("%d\n",name) ;

	// forEach(arr1,increment1,first);

	// map(arr1, arr2, increment_1, first);
	// printf("%d\n",*(arr2.base) );
	// printf("%d\n",*(arr2.base+1));
	// printf("%d\n",*(arr2.base+2));
	// printf("%d\n",*(arr2.base+3));

	// int *res = findFirst(arr1, isEven, NULL);
	// printf("find first isEven %d\n",*res );
	// printf("find first isDivisible %d\n",*((int *)findFirst(arr1, isDivisible, first)));
	// printf("find last isDivisible %d\n",*((int *)findLast(arr1, isDivisible, first)));
	// printf("count of isDivisible %d\n",count(arr1, isDivisible, first) );
	// printf("count of isEven %d\n",count(arr1, isEven, first) );

	// int maxItems = 4;
	// ArrayUtil destination = create(sizeof(int),maxItems);
	// void* dest = &destination;
	// int result = filter(arr1,isEven,first,&dest,maxItems);
	// printf("length of destination %d\n",result );
	// printf("%d\n",destination.base[0] ); 
	// printf("%d\n",destination.base[1] );
	// printf("%d\n",destination.base[2] );
	// printf("%d\n",destination.base[3] );

	
	return 0;
};
