#include <iostream>
#include "List_Container.h"

using namespace std;

int main() {
    list<int> mylist;
    mylist.push_back(100);
    mylist.push_back (200);
    mylist.push_back (300);
    mylist.push_back (400);
    mylist.push_back (500);

    list<int>::Iterator iterator1 = mylist.Begin();
    //iterator1++;
    list<int>::Iterator iterator2 = mylist.End();
    //iterator2--;
    mylist.erase(iterator1,iterator2);


    /*list<int> newmylist = mylist;

    list<int>::Iterator iterator1 = mylist.Begin();
    mylist.splice(iterator1,newmylist);*/


    return 0;
}
