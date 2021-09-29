//
// 6. *Реализовать очередь.
//

#include <stdio.h>
#include <stdlib.h>

// Нода связного списка
struct QNode 
{
	int key;
	struct QNode* next;
};


// Структура очереди с двумя ссылками на начало и конец связного списка
struct Queue 
{
	struct QNode *front;
	struct QNode *rear;
};

//Создание новой ноды связного списка. 
struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

//Создание пустой очереди
struct Queue* createQueue(void)
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

// Добавление ноды в очередь
void enQueue(struct Queue* q, int k)
{
	// Создание ноды 
	struct QNode* temp = newNode(k);

	// Если очередь пуста то первая нода является и головой и хвостом одновременно
	if (q->rear == NULL) 
	{
		q->front = temp;
		q->rear = temp;
		return;
	}

	// Добавляем новую ноду в конец 
	q->rear->next = temp;
	q->rear = temp;
}

// Удаление ноды по ключу
void deQueue(struct Queue* q)
{
	// Если очередь пуста то return NULL. 
	if (q->front == NULL)
		return;

	// Сохраняем предыдущиее значение головы, и перемещаем front на одну ноду вперед 
	struct QNode* temp = q->front;

	q->front = q->front->next;

	//Если голова стала NULL, то меняем конецтакже на NULL 
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}


int testQueue(void)
{
	struct Queue* q = createQueue();
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
