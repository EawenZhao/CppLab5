#include <iostream>
#include "List_Container.h"

using namespace std;

int main() {
    list<int> mylist;
    mylist.push_back(100);
    mylist.push_back (200);
    mylist.push_back (300);
    list<int>::Iterator iterator1 = mylist.Begin();
    iterator1++;
    mylist.Insert(iterator1, 50);

    /*list<int> newtest = test;

    list<int>::Iterator iterator1 = test.Begin();
    iterator1++;
    list<int>::Iterator iterator2 = test.End();
    test.erase(iterator1, iterator2);

    iterator1 = test.Begin();
    test.splice(iterator1,newtest);*/


    return 0;
}
