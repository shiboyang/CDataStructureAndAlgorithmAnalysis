//
// Created by shiby on 22-9-8.
//

#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>

node* link_init()
{
	return NULL;
}

node* link_find_node(node* head, datatype d)
{
	node* pnode = NULL;
	while (head->next)
	{
		if (head->data == d)
		{
			pnode = head;
			break;
		}
		head = head->next;
	}

	return pnode;
}

node* link_find(node* head, int index)
{
	int i = 0;
	node* pnode = NULL;
	while (1)
	{
		if (i == index)
		{
			pnode = head;
			break;
		}
		if (head->next == NULL)
			break;
		head = head->next;
		i++;
	}
	return pnode;
}

void link_insert(node* head, datatype d, int index)
{
	node* fined_node = link_find(head, index);
	if (fined_node == NULL)
	{
		printf("Not fined node of index %d", index);
		return;
	}
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = d;
	new_node->next = fined_node->next;
	fined_node->next = new_node;
}

void link_delete(node* head, datatype d)
{
	node* previous_node = NULL;
	node* fined_node;
	while (1)
	{
		if (head->next == NULL)
			break;
		if (head->next->data == d)
		{
			previous_node = head;
			break;
		}
		head = head->next;
	}

	if (previous_node == NULL)
	{
		printf("Can not fined data: %d", d);
		return;
	}
	fined_node = previous_node->next;
	previous_node->next = fined_node->next;
	free(fined_node);
}

void link_display(node* head)
{
	while (head->next)
	{
		printf("%d", head->data);
		head = head->next;
	}
}