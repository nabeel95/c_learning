typedef struct Numbers{
	void* num;
	struct Numbers *next;
} numbers;


typedef struct list{
	numbers *first;
	numbers *last;
	int length;
} linkedList;

linkedList createList(void);
int add_to_list(linkedList *,void *);
void *get_first_element(linkedList list);
void *get_last_element(linkedList list);

typedef void (*ElementProcessor)(void *);
void forEach(linkedList, ElementProcessor e);

void * getElementAt(linkedList, int );
int indexOf(linkedList, void *);
void * deleteElementAt(linkedList *, int);
int asArray(linkedList, void **, int maxElements);

typedef int MatchFunc(void* hint, void* item);
linkedList  filter(linkedList, MatchFunc, void *hint );

linkedList reverse(linkedList);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);
linkedList map(linkedList, ConvertFunc, void * );


typedef void* Reducer(void* hint, void* previousItem, void* item);
void* reduce(linkedList, Reducer, void *hint, void *initialValue);

