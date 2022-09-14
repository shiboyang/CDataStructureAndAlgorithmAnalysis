//
// Created by shiby on 22-9-14.
//

#include "list.h"

int main() {
    List list;
    for (int i = 0; i < 10; ++i) {
        list.append(i);
    }
    list.insert(100, 3);
    list.display();
    return 0;
}
