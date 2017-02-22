#include <stdio.h>
#define STATIC_MAX_SIZE 5

struct staticStack{
    int arr[STATIC_MAX_SIZE];
    int top;
};

struct dynamicStack{
    int *arr;
    int top;
    int size;
};

// STATIC STACK
int static_isFull(struct staticStack *stack){
    if (stack->top == (STATIC_MAX_SIZE - 1))
        return 1;
    return 0;
}

int static_isEmpty(struct staticStack *stack){
    if (stack->top == -1)
        return 1;
    return 0;
}

int static_peek(struct staticStack *stack){
    int element;
    element = stack->arr[stack->top];
    printf("Peeked element - arr[%d] = %d\n", stack->top, element);
    return element;
}

int static_pop(struct staticStack *stack){
    int element;
    if (!static_isEmpty(stack)){
        element = stack->arr[stack->top];
        printf("Popped element - arr[%d] = %d\n", stack->top, element);
        stack->top--;
        return element;
    }
    else{
        printf("Can't pop - stack is empty.\n");
    }
    return -1;
}

void static_push(struct staticStack *stack, int element){
    if (!static_isFull(stack)){
        stack->top = stack->top + 1;;
        stack->arr[stack->top] = element;
        printf("Pushed element - arr[%d] = %d\n", stack->top, element);
    }
    else{
        printf("Can't push - stack is full.\n");
    }
}

void static_init(struct staticStack *stack){
    stack->top = -1;
}

// DYNAMIC STACK
int dynamic_isFull(struct dynamicStack *stack){
    if (stack->top == (stack->size - 1))
        return 1;
    return 0;
}

int dynamic_isEmpty(struct dynamicStack *stack){
    if (stack->top == -1)
        return 1;
    return 0;
}

int dynamic_peek(struct dynamicStack *stack){
    int element;
    element = stack->arr[stack->top];
    printf("Peeked element - arr[%d] = %d\n", stack->top, element);
    return element;
}

int dynamic_pop(struct dynamicStack *stack){
    int element;
    if (!dynamic_isEmpty(stack)){
        element = stack->arr[stack->top];
        printf("Popped element - arr[%d] = %d\n", stack->top, element);
        stack->top--;
        return element;
    }
    else{
        printf("Can't pop - stack is empty.\n");
    }
    return -1;
}

void dynamic_push(struct dynamicStack *stack, int element){
    if (dynamic_isFull(stack)){
        // allocate more memory
        stack->size *= 2;
        stack->arr = (int*)realloc(stack->arr, stack->size * sizeof(int));
        printf("Allocated more memory for a dynamic stack, now its size = %d\n", stack->size);
    }
    stack->top = stack->top + 1;;
    stack->arr[stack->top] = element;
    printf("Pushed element - arr[%d] = %d\n", stack->top, element);
}

void dynamic_init(struct dynamicStack *stack){
    stack->top = -1;
    stack->size = STATIC_MAX_SIZE;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
}

int main(int argc, char *argv[]){

    // STATIC STACK USAGE EXAMPLE
    struct staticStack stack;
    struct dynamicStack dynStack;
    printf("--- STATIC STACK ---\n");
    static_init(&stack);
    static_push(&stack, 5);
    static_push(&stack, 2);
    static_push(&stack, 3);
    static_push(&stack, 4);
    static_push(&stack, -20);
    static_push(&stack, 99999);
    static_pop(&stack);
    static_peek(&stack);
    static_pop(&stack);

    // DYNAMIC STACK USAGE EXAMPLE
    printf("\n--- DYNAMIC STACK ---\n");
    dynamic_init(&dynStack);
    dynamic_push(&dynStack, 90);
    dynamic_push(&dynStack, 100);
    dynamic_push(&dynStack, 110);
    dynamic_push(&dynStack, 120);
    dynamic_push(&dynStack, 130);
    dynamic_push(&dynStack, 140);
    dynamic_push(&dynStack, 150);
    dynamic_pop(&dynStack);
    dynamic_pop(&dynStack);
    return 0;
}
