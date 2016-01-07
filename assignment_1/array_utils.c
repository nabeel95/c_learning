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
};

int isEven(void* hint, void* item){
	return (*(int *)item%2)==0;
};


int isDivisible(void* hint, void* item){
	return (*(int *)item % *(int *)hint ==0);
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int index=0;
	void *item;
	for(int i = 0;i<util.length;i++){
		item = &util.base[i];
		if(match(hint,item)){
			index=i;
			return (item);
		}
	}
	return NULL;	
};
void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int index=0, count=0;
	void *item;
	for(int i=0;i<util.length;i++){
		item= &util.base[i];
		if(match(hint,item)){
			index=i;
			count++;
		}
	}
	if(count)
		return item;
	return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int count=0;
	for(int i=0;i<util.length;i++){
		void *item= &util.base[i];
		if(match(hint,item)){
			count++;
		}
	}
	if(count)
		return count;
	return 0;
};

int filter(ArrayUtil util, MatchFunc* match, void *hint, void** dest, int maxItems ){
	ArrayUtil *destination = *dest;
	int count=0;
	for(int i=0;i<util.length;i++){
		void *item= &util.base[i];
		if(match(hint,item)){
			destination->base[count]=util.base[i];
	 		count++;
		}
		if(count==maxItems)
			break;
	}
	return count;
};




