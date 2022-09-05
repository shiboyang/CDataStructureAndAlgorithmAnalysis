//
// Created by shiby on 22-9-5.
//

#include <stdio.h>
#include <stdlib.h>
#include "sequence_queue.h"

void queue_init(QUEUE* pq)
{
	pq->front = pq->rare = 0;
}

bool queue_empty(const QUEUE* pq)
{
	return (pq->front == pq->rare) ? true : false;
}
bool queue_full(const QUEUE* pq)
{
	return (pq->front + 1 == MAXSIZE) ? true : false;
}

void queue_display(QUEUE q)
{
	while (!queue_empty(&q))
	{
		printf("%d\n", q.data[q.front]);
		q.front++;
	}
}

datatype queue_delete(QUEUE* pq)
{
	if (queue_empty(pq))
	{
		printf("This queue has queue_empty.");
		exit(-1);
	}
	datatype data = pq->data[pq->front];
	pq->front++;
	return data;
}

datatype queue_get(QUEUE* pq)
{
	if (queue_empty(pq))
	{
		printf("This queue is queue_empty.");
		exit(-1);
	}
	return pq->data[pq->front];
}

bool queue_insert(QUEUE* pq, datatype d)
{
	if (queue_full(pq))
	{
		printf("This Queue is queue_full.");
		return false;
	}
	pq->data[pq->rare] = d;
	pq->rare++;
	return true;
}