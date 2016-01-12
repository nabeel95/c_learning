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

int add_to_list(linkedList *list,void *number){
	numbers *b = (numbers *)malloc(sizeof(numbers));
	b->num = number;
	b->next = NULL;
	b->previous = NULL;
	if(list->length == 0){
	  list->first = list->last = b;
	}
	else{
	  b->previous = list->first;
	  list->first = b;      
	  b->next = NULL;
	}
	list->length++;
	free(b->next);
	return 0;
};

void *get_first_element(linkedList list){
	return list.first->num;
};

void *get_last_element(linkedList list){
	return list.last->num;
};

void forEach(linkedList list, ElementProcessor e){
	numbers *b = list.first;
	for(int i=0;i<list.length;i++){
		e(b->num);
		b=b->previous;
	}
};





