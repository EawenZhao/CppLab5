#include <iostream>
#include "List_Container.h"

using namespace std;

int main() {
    list<int> test;
    test.push_back(5);
    test.push_back(4);
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);

    list<int>::Iterator iterator = test.Begin();
    iterator++;
    iterator++;
    test.Insert(iterator,10);

    return 0;
}
