//
//  Stack.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 28.09.2021.
//

#include "Stack.h"
#define T char

Stack *newStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, T value) {
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = stack->head;
    stack->head = tmp;
    stack->size++;
}

T pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty");
        return ' ';
    }
    // Временный указатель
    Node *next = NULL;
    // Значение "наверху" списка
    T value;
    value = stack->head->value;
    next = stack->head;
    stack->head = stack->head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    stack->size--;
    return value;
}

void printStack(Stack *stack) {
    Node *current = stack->head;
    while (current != NULL) {
        printf("%c", current->value);
        current = current->next;
    }
    free(current);
    printf("\n");
}

void clearStack(Stack *stack) {
    Node *current = stack->head;
    while (current != NULL) {
        free(current);
        current = current->next;
    }
    free(current);
    free(stack);
}

// Если просто скопировать стэк, то порядок будет обратный в отличии от источнка
// Поэтому я использовал следующее простое решение:
// Создаем временный стэк и туда копируем все с источника
// Далее из временного стэка копируем уже в новый стэк для выдачи
// Таким образом порядок будет как в источнике
Stack *copyStack(Stack *source) {
    Stack *tmp = newStack();
    Stack *stack = newStack();
    Node *current = source->head;
    while (current != NULL) {
        push(tmp, current->value);
        current = current->next;
    }
    free(current);
    current = tmp->head;
    while (current != NULL) {
        push(stack, current->value);
        current = current->next;
    }
    free(tmp);
    free(current);
    return stack;
}

// Проверка синтаксиса скобок
void checkItem(Stack *stack, T value) {
    if (stack->head != NULL) {
        T lastValue = stack->head->value;
        switch (value) {
            case '(':
                if (lastValue == ')') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
            case ')':
                if (lastValue == '(') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
                
            case '{':
                if (lastValue == '}') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
            case '}':
                if (lastValue == '{') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
                
            case '[':
                if (lastValue == ']') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
            case ']':
                if (lastValue == '[') {
                    pop(stack);
                } else {
                    push(stack, value);
                }
                break;
                
            default:
                break;
        }
    } else {
        push(stack, value);
    }
}

int checkSyntax(T *exp) {
    int index = 0;
    Stack *myStack = newStack();
    while (exp[index] != '~') {
        switch (exp[index]) {
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
                checkItem(myStack, exp[index]);
                break;
            default:
                break;
        }
        index++;
    }
    printf("Проверка выражения: %s\n", exp);
    if (myStack->size == 0) {
        printf("УСПЕХ! Скобки используются корректно!\n");
        printf("--------------------\n");
        clearStack(myStack);
        return 0;
    } else {
        printf("ОШИБКА! Некорректное использование скобок!\n");
        printf("--------------------\n");
        clearStack(myStack);
        return -1;
    }
}
