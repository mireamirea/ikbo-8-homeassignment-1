#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 3		/* Initial size of stack */
#define INCREASE 2		/* Increase of stack */


/* Stack */

struct stack {

	int *data;
	int size;
	int top;

};


void init(struct stack *stk);
void push(struct stack *stk, int a);
int pop(struct stack *stk);
int peek(struct stack *stk);
int isEmpty(struct stack *stk);
void stkPrint(struct stack *stk);
void deleteStack(struct stack *stk);
void resize(struct stack *stk);



int main() {

	struct stack stk;

	init(&stk);


	/* Test */

	push(&stk, 10);
	push(&stk, -4);
	push(&stk, 5);
	push(&stk, 7);
	push(&stk, 23);
	push(&stk, 0);
	push(&stk, -3);
	pop(&stk);
	push(&stk, 7);
	push(&stk, -80);
	stkPrint(&stk);
	
	
	deleteStack(&stk);
	
	
	return 0;
}



/* Initialization stack */

void init(struct stack *stk) {

	stk->size = INIT_SIZE;
	stk->data = malloc(stk->size * sizeof(int));
	stk->top = 0;

}



/* Clearing memory */

void deleteStack(struct stack *stk) {

	free(stk->data);

}



/* Push element on top stack */

void push(struct stack *stk, int a) {
	
	if (stk->top >= stk->size) {
		resize(stk);
	}

	stk->data[stk->top] = a;
	stk->top++;
	printf("Element %d pushed. \n\n", a);


}



/* Delete element from top stack */

int pop(struct stack *stk) {

	if (stk->top > 0) {


		stk->top--;
		printf("Element %d deleted. \n\n", stk->data[stk->top]);

		return stk->data[stk->top];
	}

	else {

		printf("Stack is empty! \n\n");
		return 0;
	}

}



/* Returns the current element */

int peek(struct stack *stk) {

	if (stk->top > 0) {

		return stk->data[stk->top - 1];
	}

	else {

		printf("Stack is empty! \n\n");
		return 0;
	}

}



/* Checking stack on emptiness */

int isEmpty(struct stack *stk) {

	if (stk->top == 0) {
		return 1;
	}

	else {
		return 0;
	}

}


/* Resize stack */

void resize(struct stack *stk) {

	stk->size += INCREASE;
	stk->data = realloc(stk->data, stk->size * sizeof(int));

}



/* Printing */

void stkPrint(struct stack *stk) {

	int i, j = 0;

	i = stk->top;
	if (isEmpty(stk) == 1) {

		printf("Stack is empty! \n");
		return;
	}

	do {

		if (j == 0) {
			printf("Outputting elements stack: \n");
			j++;
		}

		i--;
		printf("Element %d: ", i + 1);
		printf("%d\n", stk->data[i]);

	} while (i>0);

}



