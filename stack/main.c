/*
 main.c
 stack
 
 Created by Денис Скоробогатов on 01.03.17.
 Copyright © 2017 Denis Skorobogatov. All rights reserved.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 255

typedef struct _stack {
    char *info;
    struct _stack *pointer;
} stack;

int readline(char **input)
{
    char *_input = malloc(sizeof(char));
    char c;
    int i = 0;
    while((c = getchar()) != '\n')
    {
        if (i < MAXLENGTH)
        {
            _input[i] = c;
            i++;
            _input = realloc(_input, sizeof(char) * (i + 1));
        }
    }
    _input[i] = '\0';
    *input = _input;
    return i;
}

stack *push(stack *str) /* returns the top element */
{
    char *input;
    stack *element = malloc(sizeof(stack));
    element->pointer = str;
    printf("GIMME INFO\n");
    getchar();
    readline(&input);
    element->info = input;
    return element;
}

stack *pop(stack *str) /* deletes the top element, returns bottom */
{
    stack *pointer = str->pointer;
    free(str);
    return pointer;
}

void peek(stack *str)
{
    printf("INFO: ");
    puts(str->info);
    printf("Previous location: %p\n", str->pointer);
    return;
}

int main(int argc, const char * argv[]) {
    stack *element = malloc(sizeof(stack));
    int action;
    /* stack init */
    element->pointer = NULL;
    element->info = "first element";
    while(1)
    {
        scanf("%d", &action);
        /* 1 - push, 2 - pop, 3 - peek */
        if (action == 1) /* push */
        {
            element = push(element);
            action = 0;
        }
        if (action == 2) /* pop */
        {
            if (element == NULL)
                printf("Nothing to pop\n");
            else
                element = pop(element);
            action = 0;
        }
        if (action == 3) /* peek */
        {
            if (element == NULL)
                printf("Nothing to peek\n");
            else
                peek(element);
        }
        if (action == 4)
            break;
        action = 0;
    }
    return 0;
}
