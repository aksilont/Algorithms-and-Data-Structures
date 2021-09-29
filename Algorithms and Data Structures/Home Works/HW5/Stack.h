//
//  Stack.h
//  Algorithms and Data Structures
//
//  Created by Aksilont on 28.09.2021.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#define T char

// Опишем структуру узла списка
typedef struct TNode {
    T value;
    struct TNode *next;
} Node;

typedef struct _Stack {
    Node *head;
    int size;
} Stack;

Stack *newStack(void);
void push(Stack *stack, T value);
T pop(Stack *stack);
void printStack(Stack *stack);
void clearStack(Stack *stack);

Stack *copyStack(Stack *source);

int checkSyntax(T *exp);

#endif /* Stack_h */
