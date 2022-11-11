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



    list<int>::Iterator iterator1 = test.Begin();
    iterator1++;
    list<int>::Iterator iterator2 = test.End();
    test.erase(iterator1, iterator2);


    return 0;
}
