#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "assert.h"

	int num1=3;
	void *n1=&num1;
	int num2=4;
	void *n2=&num2;
	int num3=5;
	void *n3=&num3;

void increment(void *element){
	*(int *)element = *(int *)element+1;
}

void test_createList_should_return_empty_list(){
  linkedList list = createList();
  assert(list.first == NULL);
  assert(list.last == NULL);
  assert(list.length == 0);
};

void test_add_to_list_should_add_number_into_the_linked_list(){
  linkedList list = createList();
  add_to_list(&list, n1);
  assert(list.first -> num == n1);
  assert(list.last -> num == n1);
  assert(list.length == 1);
};

void test_for_add_to_list(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	assert(*(int *)data.last->num==3);
	assert(*(int *)data.first->num==5 );
}

void test_for_get_first_element(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	int head = *(int *)(get_first_element(data));
	assert(head==5);
};
void test_for_get_last_element(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	int tail = *(int *)(get_last_element(data));
	assert(tail==3);
};

void test_for_forEach(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	forEach(data,increment);
	int head = *(int *)(get_first_element(data));
	int tail = *(int *)(get_last_element(data));
	assert(head==6);
	assert(tail==4);		
};
