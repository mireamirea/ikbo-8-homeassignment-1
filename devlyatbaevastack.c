#include <stdio.h>
#include <stdlib.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define STACK_MAX_SIZE 20
typedef int T;

/*Структура стека*/
typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

/*Добавляем новый элемент*/
void push(Stack_t *stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

/*Возвращаем элемент с вершины и переходим к следующему*/ 
T pop(Stack_t *stack) {
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}

/*Возвращаем текущий элемент с вершины*/ 
T peek(const Stack_t *stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->size - 1];
}

void printStackValue(const T value) {
    printf("%d", value);
}
 
/*Печать элементов стека*/
void printStack(const Stack_t *stack, void (*printStackValue)(const T)) {
    int i;
    int len = stack->size - 1;
    printf("stack %zd > ", stack->size);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

void main() {
	Stack_t stack;
	stack.size = 0;

	push(&stack, 3);
	printStack(&stack, printStackValue);
	push(&stack, 5);
	printStack(&stack, printStackValue);
	push(&stack, 7);
	printStack(&stack, printStackValue);
	pop(&stack); 
	printStack(&stack, printStackValue);
	pop(&stack); 
	printStack(&stack, printStackValue);
	pop(&stack); 
	printStack(&stack, printStackValue);
}

