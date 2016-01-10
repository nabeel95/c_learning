#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_utils.h"


int areEqual(ArrayUtil a, ArrayUtil b){
	int count=0;
	if(a.length==b.length && a.typeSize==b.typeSize){
		for(int i = 0;i<a.length;i++){
			if(*((unsigned char*)a.base+i*a.typeSize) == *((unsigned char*)b.base+i*b.typeSize))
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

int findIndex(ArrayUtil util, void* element){
	for(int i=0;i<util.length;i++){
		if(*((unsigned char*)util.base+i*util.typeSize) - *(unsigned char *)element==0) return i;
	}
	return -1;
};


void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int index=0,count=0,*notThere=NULL;
	void *item;
	for(int i = 0;i<util.length;i++){
		item = &util.base[i];
		if(match(hint,item)){
			return item;
			exit(0);
		}
	}
	return notThere;	
};
void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	int index=0,count=0,*notThere=NULL;
	void *item;
	for(int i=0;i<util.length;i++){
		item= &util.base[i];
		if(match(hint,item)){
			index=i;
			count++;
		}
	}
	if(count>0)
		return util.base+index;
	return notThere;
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

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
		int count=0,i;
		for(i=0;i<source.length;i++){
			convert(hint,source.base+i,destination.base+i);
		}
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	int count=0,i;
	for(i=0;i<util.length;i++){
		operation(hint,util.base+i);
	}
};

// void* ReducerFunc(void* hint, void* previousItem, void* item);

void *reduce(ArrayUtil util, ReducerFunc * reducer, void *hint, void *initialValue){
  void *item = util.base,*prevItem = initialValue;
  for(int i = 0; i < util.length; i++){
  	void *pointer = reducer(hint, prevItem, item);
    prevItem = pointer;
    item = item + util.typeSize;
  };
  return prevItem;
};











