#include <stdio.h>
#define _STACK_ARRAY_H_
#define SIZE_STACK_ARRAY 100

const int okStackArray = 0;											
const int fullStackArray = 1;										
const int emptyStackArray = 2;										

extern int errorStackArray;

typedef int stackArrayBaseType;

typedef struct {
	stackArrayBaseType buf[SIZE_STACK_ARRAY];						
	unsigned uk;												
} StackArray;


int errorStackArray;


void initStackArray(StackArray *S) {
	S->uk = 0;
	errorStackArray = okStackArray;
}


void putStackArray(StackArray *S, stackArrayBaseType E) {

	if (isFullStackArray(S)) {
		return;
	}
	
	S->buf[S->uk] = E;				
	S->uk++;							 

}

int isFullStackArray(StackArray *S) {
	if (S->uk == SIZE_STACK_ARRAY) {
		errorStackArray = fullStackArray;
		return 1;
	}
	return 0;
}

int isEmptyStackArray(StackArray *S) {
	if (S->uk == 0) {
		errorStackArray = emptyStackArray;
		return 1;
	}
	return 0;
}

void getStackArray(StackArray *S, stackArrayBaseType *E) {


	if (isEmptyStackArray(S)) {
		return;
	}

	*E = S->buf[S->uk - 1];		
	S->uk--;							

}

		
int main() {

	printf("Stacl on the arrays");

	StackArray S;
	stackArrayBaseType a;

	initStackArray(&S);
	putStackArray(&S, 10);
	putStackArray(&S, 15);

    puts("\tEntered: 10, 15\n\tPrint: ");
	getStackArray(&S, &a);
	printf("%d ", a);
	getStackArray(&S, &a);
	printf("%d", a);

	return 0;
}
