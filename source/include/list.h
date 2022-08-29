//
// Created by shiby on 22-8-11.
//

#ifndef CDATASTRUCTUREANDALGORITHMANALYSIS_LIST_H
#define CDATASTRUCTUREANDALGORITHMANALYSIS_LIST_H

struct Node;
//struct element;
typedef int ElementType;
struct list;

typedef struct Node *PtrToNode;
typedef struct list *  List;
typedef PtrToNode Position;

List init_list(List l);

List clean(List l);

int is_empty(List l);

int is_last(Position p);

Position find(List l, ElementType element);

void delete(ElementType element, List l);

Position find_previous(List l, ElementType element);

void insert(List l, ElementType element);

void delete_list(List l);

Position header(List l);

Position first(List l);

Position advance(Position p);


#endif //CDATASTRUCTUREANDALGORITHMANALYSIS_LIST_H

