#include <stdio.h>
#define STACK_MAX_SIZE 5
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101

struct st {
int num;
int elem[STACK_MAX_SIZE];} *stack=NULL;

int main(void){
    int k,e;
    stack=(struct st*) malloc(sizeof(struct st));
    stack->num=0;
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
	pop(stack);
	printf("\nElem deleted\n");
	break;
case 3:	printf("\nPeek elem=%d", peek(stack) );
        break;
case 4: printf("\nStack:\n");
        printst(stack);
        break;
case 0: break;
default:
            printf( "Error.\n" );
}
}
}


void push(struct st *stack, int value) {
    if (stack->num >= STACK_MAX_SIZE) {
            printf("STACK_OVERFLOW\n");
        exit(STACK_OVERFLOW);
    }
    stack->elem[stack->num] = value;
    stack->num++;
}

int pop(struct st *stack) {
    if (stack->num <= 0) {
             printf("STACK_UNDERFLOW\n");
        exit(STACK_UNDERFLOW);
    }
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
