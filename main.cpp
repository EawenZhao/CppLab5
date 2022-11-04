#include <iostream>
#include "List_Container.h"

using namespace std;

int main() {
    list<int> test;
    test.push_back(4);
    test.push_front(3);
    test.push_front(2);
    test.push_back(1);
    return 0;
}
