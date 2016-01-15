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
	char name1[10]="nabeel";
	void *n4=&name1;
	int num5=6;
	void *n5=&num5;
	int num6=0;
	void *n6=&num6;

void multiply(void *hint,void *sourceItem,void *destinationitem){
	*(int *)destinationitem = (*(int *)hint)*(*(int *)sourceItem);
};

void increment(void *element){
	*(int *)element = *(int *)element+1;
}

int isEven(void* hint, void* item){
	return (*(int *)item%2==0);
};

void* sum(void* hint, void* previousItem, void* item){
	int result = *(int *)previousItem+*(int *)item; 
	return &result;
};

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
	numbers *fist = get_first_element(data);
	assert(*(int *)fist->num==5);
};
void test_for_get_last_element(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	numbers *lst = get_last_element(data);
	assert(*(int *)lst->num==3);
};

void test_for_forEach(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	forEach(data,increment);
	numbers *fist = get_first_element(data);
	numbers *lst = get_last_element(data);
	assert(*(int *)fist->num==6);
	assert(*(int *)lst->num==4);	
};

void test_for_get_element_at(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	numbers *index0 = getElementAt(data,0);
	numbers *index1 = getElementAt(data,1);
	numbers *index2 = getElementAt(data,2);
	assert(*(int *)index0->num==5);
	assert(*(int *)index1->num==4);
	assert(*(int *)index2->num==3);
}

void test_for_deleteElementAt(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	deleteElementAt(&data,1);
	numbers* index1 = getElementAt(data,1);
	assert(*(int *)index1->num==3);
	assert(data.length==2);
}

void test_for_as_array(){
	linkedList data = createList();
	void *arr[10];
	int maxLength=3;
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	int res=asArray(data,arr,maxLength);
	assert(res==3);
	assert(*(int *)arr[0]==5);
	assert(*(int *)arr[1]==4);
	assert(*(int *)arr[2]==3);
};

void test_for_filter(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	add_to_list(&data,n5);
	linkedList result = filter(data, isEven, n1 );
	numbers *b = result.first;
	assert(*(int *)b->num==4);
	assert(*(int *)b->next->num==6);
	assert(result.length==2);
};

void test_for_reverse(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	add_to_list(&data,n5);
	linkedList result = reverse(data);
	numbers *b = result.first;
	assert(*(int *)b->num==3);
	assert(*(int *)b->next->num==4);
	assert(*(int *)b->next->next->num==5);
	assert(*(int *)b->next->next->next->num==6);
}

void test_for_map(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	add_to_list(&data,n5);
	map(data,multiply,n1);
	numbers *b = data.first;
	assert(*(int *)b->num==18);
	assert(*(int *)b->next->num==15);
	assert(*(int *)b->next->next->num==12);
	assert(*(int *)b->next->next->next->num==9);
}

void test_for_reduce(){
	linkedList data = createList();
	add_to_list(&data,n1);
	add_to_list(&data,n2);
	add_to_list(&data,n3);
	add_to_list(&data,n5);
	void *result=reduce(data,sum,n1,n6);
	assert(*(int *)result==18 );
};

// int main(){
// 	linkedList data = createList();
// 	add_to_list(&data,n1);
// 	add_to_list(&data,n2);
// 	add_to_list(&data,n3);
// 	add_to_list(&data,n5);
// 	void *result=reduce(data,sum,n1,n6);
// 	printf("%d\n",*(int *)result );

// };