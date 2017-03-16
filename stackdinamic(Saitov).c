#include <stdio.h>
#include <stdlib.h>
#define STACK_UNDERFLOW -101


struct st {
int num;
int *elem;} *stack=NULL;


void push(struct st *stack, int value) {
    stack->elem = (int*) realloc (stack->elem, sizeof(int)*(stack->num+1));
    stack->elem[stack->num] = value;
    stack->num++;
}

int pop(struct st *stack) {
    if (stack->num <= 0) {
             printf("STACK_UNDERFLOW\n");
        exit(STACK_UNDERFLOW);
    }
    stack->elem= (int*) realloc (stack->elem,sizeof(int)*(stack->num));
    stack->num--;
    return stack->elem[stack->num];
}

int peek(struct st *stack) {
    if (stack->num <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->elem[stack->num - 1];
}

void printst(struct st * stack) {
	if (stack->num > 0) {
		int i = 0;
		for (i = 0; i < stack->num; i++) {
    printf("%d\n", stack->elem[i]);
		}

	} else
		printf("Pusto\n");
}

int main(void){
    int k,e;
    stack=(struct st*) malloc (sizeof(struct st));
    stack->num=0;
    stack->elem= (int*) malloc (sizeof(int));
    while (k!=0)
{
     printf("\n1.Add element\n2.Del elem\n3.Print peek element\n4.Print stack\n0.End\n");
    scanf("%d", &k);
    switch(k){
case 1: printf("\nElem=");
    scanf("%d", &e);
    push(stack, e);
    break;
case 2:
	printf("\nElem  %d deleted\n", pop(stack));
	break;
case 3:	printf("\nPeek elem=%d\n", peek(stack) );
        break;
case 4: printf("\nStack:\n");
        printst(stack);
        break;
case 0: break;
default:
            printf( "Error.\n" );
}
}
return 0;
}
