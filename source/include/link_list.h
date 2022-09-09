//
// Created by shiby on 22-9-8.
//

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#define datatype int
typedef struct link_node
{
	datatype data;
	struct link_node* next;
} node;

node* link_init();
void link_display(node*);
node* link_find(node* head, int i);
void link_insert(node*, datatype, int);
void link_delete(node*, datatype);

#endif //_LINK_LIST_H_
