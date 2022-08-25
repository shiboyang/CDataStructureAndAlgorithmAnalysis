//
// Created by shiby on 22-8-11.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"



struct Node {
  ElementType element;
  Position next;
};

struct list {
  Position head;
  int length;
};

List init_list(List l) {
  Position p = (PLIST)malloc(sizeof(Node));
  l->head = p;
  l->head->element = 0;
  l->length = 0;
  return l;
}

List clean(List l) {
  Position p;
  p = l->head;
  while (p->next != NULL) {
	p->element = 0;
	p = p->next;
  }
  return l;
}

int is_empty(List l) {
  return l->length == 0;
}

int is_last(Position p) {
  return p->next == NULL;
}

/*
 * Find element in list
 * found return position pointer else return NULL
 * */
Position find(List l, ElementType element) {
  Position p;
  p = l->head;
  while (p->next != NULL && p->element != element) {
	p = l->head->next;
  }
  if (p->next == NULL && p->element != element)
	return NULL;
  else
	return p;
}

/*
 * find previous element in list.
 * */
Position find_previous(List l, ElementType element) {
  Position p = l->head;
  while (p->next != NULL && p->next->element != element)
	p = p->next;

  return (p->next == NULL) ? NULL : p;
}

/*
 * Delete element in the list
 *
 *
 * */
void delete(ElementType element, List l) {

}
