#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

linkedList createList(void){
	linkedList myList = *(linkedList *)malloc(sizeof(linkedList));
	myList.first=NULL;
   	myList.last=NULL;
   	myList.length=0;
   	return myList;
};

int add_to_list(linkedList *list,void *value){
	numbers *b = (numbers *)malloc(sizeof(numbers));
	b->num = value;
	b->next = NULL;
	if(list->length == 0){
		list->first = list->last = b;
	}
	else{
		b->next=list->first;
		list->first=b;
	}
	list->length++;
	// free(b->next);
	return 0;
};
void *get_first_element(linkedList list){
	return list.first;
};
void *get_last_element(linkedList list){
	return list.last;
};
void forEach(linkedList list, ElementProcessor e){
	numbers *b = list.first;
	for(int i=0;i<list.length;i++){
		e(b->num);
		b=b->next;
	}
};
void * getElementAt(linkedList list, int index ){
	void* notThere = (void*)malloc(sizeof(void));
	notThere =NULL;
	if(index >=list.length)
		return notThere;
	numbers *b = list.first;
   for(int i=0;i<index;i++){
      b = b->next;
   };
   return b;
}
int indexOf(linkedList list, void * value){
	numbers *b = list.first;
	for(int i=0;i<list.length;i++){
      if(b->num == value)
      	return i;
      b = b->next;
   };
   return -1;
};
void * deleteElementAt(linkedList *list, int index){
	numbers *b = list->first;int *l=0;
	if(index==0){
		list->first=list->first->next;
	}
	if(index==list->length-1){
		numbers *c = getElementAt(*list,index-1);
		list->last=c;
	}
	else{
		numbers *prev = getElementAt(*list,index-1);
		numbers *nex =  getElementAt(*list,index+1);
		prev->next=nex;
	};
	list->length--;
	return b->num;
};

int asArray(linkedList list, void ** array, int maxElements){
	numbers *b=list.first;int i=0;
	while(b!=NULL && i<maxElements){
		array[i]=b->num;
		b=b->next;
		i++;
	};
	return i;	
};

linkedList  filter(linkedList list,MatchFunc match, void *hint ){
	linkedList listToReturn = createList();
	numbers *b = list.first;
	for(int i =0;i<list.length;i++){
		if(match(hint,b->num)){
			add_to_list(&listToReturn,b->num);
		}
		b=b->next;
	}
	return listToReturn;
};

linkedList reverse(linkedList list){
	linkedList listToReturn = createList();
	for(int i=0;i<list.length;i++){
		numbers* item = getElementAt(list,i);
		add_to_list(&listToReturn,item->num);		
	};
	return listToReturn;
};

linkedList map(linkedList list, ConvertFunc convert, void * hint){
	numbers *b = list.first;
	for(int i=0;i<list.length;i++){
		convert(hint,b->num,b->num);
		b=b->next;
	}
	return list;
};

void* reduce(linkedList list, Reducer reducer, void *hint, void *initialValue){
	numbers *b = list.first; void* prevItem = initialValue;
	for(int i=0;i<list.length;i++){
		prevItem = reducer(hint,prevItem,b->num);
		b=b->next;
	}
	return prevItem;
};















