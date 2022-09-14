//
// Created by shiby on 22-9-14.
//

#include "list.h"


Node::Node(int d, Node *pn) {
    Node::data = d;
    Node::next = pn;
}

List::List() {
    List::head = new Node;
    List::length = 0;
}

int List::count() {
    return List::length;
}

Node *List::find(int position) {
    Node *pnode = NULL;
    if (position <= List::length) {
        pnode = List::head;
        for (int i = 0; i < List::length; ++i) {
            pnode = pnode->next;
        }
    } else {
        cout << "Can not find position " << position << endl;
    }
    return pnode;
}

void List::append(datatype d) {
    Node * current_node = List::find(List::length);
    Node * node = new Node(d);
    current_node->next = node;
    List::length++;
}

void List::insert(datatype d, int position) {
    Node *fined_node = List::find(position);
    if (fined_node) {
        Node * pnode = new Node(d, fined_node->next);
        fined_node->next = pnode;
    }
}

void List::display() {

    if (List::count() > 0) {
        Node *pnode = List::head->next;
        for (int i = 0; i < List::length; ++i) {
            cout << pnode->data << endl;
            pnode = pnode->next;
        }
    } else {
        cout << "Empty List" << endl;
    }
}


