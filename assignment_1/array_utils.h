typedef struct arrayUtil{
	int *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef void* ReducerFunc(void* hint, void* previousItem, void* item);

typedef void(OperationFunc)(void* , void* );

typedef void(ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);

typedef int(MatchFunc)(void*,void*);

ArrayUtil create(int typeSize, int length);

ArrayUtil resize(ArrayUtil util, int length);

int areEqual(ArrayUtil a, ArrayUtil b);

void dispose(ArrayUtil util);

int findIndex(ArrayUtil util, int element);

int isEven(void* hint, void* item);
int isDivisible(void* hint, void* item);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);