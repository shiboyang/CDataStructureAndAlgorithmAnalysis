//
// Created by shiby on 22-9-5.
//

#include <stdbool.h>
#ifndef _SEQUENCE_QUEUE_H_
#define _SEQUENCE_QUEUE_H_

/*!
 * FIRST IN FIRST OUT
 */

#define MAXSIZE 100
#define datatype int
typedef struct sequence_queue
{
	datatype data[100];
	int front;
	int rare;
} QUEUE;

void queue_init(QUEUE*);
bool queue_empty(const QUEUE*);
bool queue_full(const QUEUE*);
void queue_display(QUEUE);
datatype queue_get(QUEUE*);
bool queue_insert(QUEUE*, datatype);
datatype queue_delete(QUEUE*);

#endif //_SEQUENCE_QUEUE_H_
