typedef struct Numbers{
	void* num;
	struct Numbers *next;
	struct Numbers *previous;
} numbers;


typedef struct list{
	numbers *first;
	numbers *last;
	int length;
} linkedList;

linkedList createList(void);


typedef void (*ElementProcessor)(void *);
// Write a generic traverse function that can go through a list and process each element.

int add_to_list(linkedList *,void *);

// Given a reference to some data, add it to list. For now, add it to the end of the list. 


void *get_first_element(linkedList list);

// This function returns the first element in the linkedList. 


void *get_last_element(linkedList list);

// This function returns the first element in the list. 


void forEach(linkedList, ElementProcessor e);

// where ElementProessor is a function pointer type with the following signature: 