//
// Created by shiby on 22-9-14.
//

#ifndef MAIN_LIST_H
#define MAIN_LIST_H

#include <iostream>

using namespace std;
#define datatype int

class Node {
public:
    datatype data;
    Node *next;

    explicit Node(int d = 0, Node *pn = nullptr);
};

class List {
private:
    Node *head;
    int length;
public:
    List();

    int count();

    void insert(int d, int position);

    void append(int d);

    Node *find(int position);

    void display();
};


#endif //MAIN_LIST_H
