#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"


int main(void){
	ArrayUtil arr1 = create(4,4);
	ArrayUtil arr2 = create(4,4);
	ArrayUtil arr3 = create(4,4);
	*(arr1.base)   = 0;
	*(arr1.base+1) = 1;
	*(arr1.base+2) = 2;
	*(arr1.base+3) = 3;

	*(arr3.base)   = 0;
	*(arr3.base+1) = 1;
	*(arr3.base+2) = 2;
	*(arr3.base+3) = 3;
	printf("are equal = %d\n",areEqual(arr1,arr3) );


	dispose(arr1);
	printf("are equal = %d\n",areEqual(arr1,arr3) );

	printf("find index-> index of given value = %d\n",findIndex(arr1,2) );

	
	return 0;
};