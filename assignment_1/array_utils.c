#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_utils.h"

int areEqual(ArrayUtil a, ArrayUtil b){
	int count=0;
	if(a.length==b.length && a.typeSize==b.typeSize){
		for(int i = 0;i<a.length;i++){
			if(a.base[i] == b.base[i])
				count++;
		}
	}
	if (count == a.length && count == b.length)
		return 1;
	return 0;
};

ArrayUtil create(int typeSize, int length) {
	ArrayUtil array;
	array.base =  (void *)calloc(length,typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
};

ArrayUtil resize(ArrayUtil util, int length) {
	util.length = length;
	util.base = (void *)realloc(util.base,util.typeSize*length);
	return util;
};

void dispose(ArrayUtil util){
		free(util.base);		
};

int findIndex(ArrayUtil util, int element){
	int count=0;
	int index=0;
	for(int i=0;i<util.length;i++){
		if(util.base[i]==element){
			index=i;
			count++;
		}
	}
	if(count>0)
		return index;
	return -1;
}






























// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//    char *str;

//    str = (char *) malloc(0);
//    strcpy(str, "dont worry about...");
//    printf("String = %s,  Address = %u\n", str, str);

//    str = (char *) realloc(str, 15);
//    strcat(str, "anything");
//    printf("String = %s,  Address = %u\n", str, str);

//    free(str);
   
//    return(0);
// }