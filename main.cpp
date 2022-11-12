#include <iostream>
#include "List_Container.h"

using namespace std;

int main() {
    list<int> mylist;
    mylist.push_back(100);
    mylist.push_back (200);
    mylist.push_back (300);

    list<int>::Iterator iterator1 = mylist.Begin();
    list<int>::Iterator iterator2 = mylist.End();
    mylist.erase(iterator1,iterator2);



    //list<int> newmylist = mylist;

    /*iterator1 = mylist.Begin();
    mylist.splice(iterator1,newmylist);*/


    return 0;
}
