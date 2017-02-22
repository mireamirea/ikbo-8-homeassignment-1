#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 15


struct stack {
	
	int data[MAX];
	int top;
	
};


void init (struct stack *stk);
void push (struct stack *stk, int a);
int pop (struct stack *stk);




int main () {
	
	struct stack stk;
	
	init(&stk);
	
	
	//тестируем
	
	push(&stk,54);
	push(&stk,5);
	pop(&stk);

 	
	
	system("pause");
	return 0;
}



// инициализация стека

void init(struct stack *stk) {

  stk->top = 0;

}


// Добавление элемента

void push(struct stack *stk, int a) {
	
	if (stk->top < MAX) {
		
		stk->data[stk->top] = a;
		stk->top++;
		
		printf("Element %d pushed. \n\n", a);
	}
	
	else {
		printf("Stack is full, amount of elements: %d \n\n", stk->top);
	}
 
}



// Удаление элемента

int pop(struct stack *stk) {
	
    if (stk->top > 0) {
        

        stk->top--;
        printf("Element %d deleted. \n\n", stk->data[stk->top] );
        
        return stk->data[stk->top];
	}
    
    else {
    	
    	printf("Stack is empty! \n\n");
    	return 0;
	}
	
}

