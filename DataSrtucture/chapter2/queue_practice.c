//
// Created by shiby on 22-9-5.
//
#include "sequence_queue.h"
#include <stdio.h>

int main(void)
{

	QUEUE queue;
	queue_init(&queue);
	printf("%u\n", queue_empty(&queue));

	for (int i = 0; i < 10; i++)
	{
		queue_insert(&queue, i);
	}
	printf("after queue_insert len(q) = %u\n", queue_empty(&queue));

	queue_display(queue);

	datatype d = queue_delete(&queue);
	printf("queue_delete element is %d\n", d);

	d = queue_delete(&queue);
	printf("queue_delete element is %d\n", d);

	d = queue_delete(&queue);
	printf("queue_delete element is %d\n", d);

	d = queue_delete(&queue);
	printf("queue_delete element is %d\n", d);

	queue_display(queue);

	return 0;
}

