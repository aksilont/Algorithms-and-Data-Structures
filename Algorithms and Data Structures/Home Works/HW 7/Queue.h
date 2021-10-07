//
//  Queue.h
//  Algorithms and Data Structures
//
//  Created by Aksilont on 06.10.2021.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

// Нода связного списка
typedef struct QNode {
    int key;
    struct QNode* next;
} QNode;

// Структура очереди с двумя ссылками на начало и конец связного списка
typedef struct Queue {
    struct QNode *front;
    struct QNode *rear;
} Queue;

QNode* newNode(int k);
Queue* createQueue(void);
void enQueue(Queue* q, int k);
int deQueue(Queue* q);
int queueIsEmpty(Queue * q);

#endif /* Queue_h */
