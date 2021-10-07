//
//  Queue.c
//  Algorithms and Data Structures
//
//  Created by Aksilont on 06.10.2021.
//

#include "Queue.h"

//Создание новой ноды связного списка.
QNode* newNode(int k) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

//Создание пустой очереди
Queue* createQueue(void) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Добавление ноды в очередь
void enQueue(Queue* q, int k) {
    // Создание ноды
    QNode* temp = newNode(k);

    // Если очередь пуста то первая нода является и головой и хвостом одновременно
    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }

    // Добавляем новую ноду в конец
    q->rear->next = temp;
    q->rear = temp;
}

// Удаление ноды по ключу
int deQueue(Queue* q) {
    int item;
    
    // Если очередь пуста то return -1.
    if (q->front == NULL)
        return -1;

    // Сохраняем предыдущиее значение головы, и перемещаем front на одну ноду вперед
    QNode* temp = q->front;
    item = q->front->key;
    
    q->front = q->front->next;
    
    //Если голова стала NULL, то меняем конец также на NULL
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    
    return item;
}

// Проверка на наличие элементов в очереди
int queueIsEmpty(Queue * q) {
    if (q->rear)
        return 0;
    else
        return 1;
}

int testQueue(void) {
    Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);
    printf("Queue Front : %d \n", q->front->key);
    printf("Queue Rear : %d", q->rear->key);
    scanf("");
    
    return 0;
}
