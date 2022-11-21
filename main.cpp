#include <iostream>
//#include "List_Container.h"
#include <list>
using namespace std;

int main() {
    list<char> letters;
    list<char>::iterator itr;
    itr = letters.begin();  //   tepref
    letters.insert(itr,'f');
    letters.insert(itr,'e');
    itr++;
    letters.insert(itr,'r');
    itr++;
    itr++;
    letters.insert(itr,'t');
    letters.insert(itr,'e');
    letters.erase(letters.begin());
    itr--;
    itr--;
    letters.insert(itr,'p');
    itr++;
    letters.insert(itr,'e');
    itr = letters.end();
    itr--;
    letters.insert(itr,'c');

    for (list<char>::iterator itr = letters.begin(); itr != letters.end() ; itr++) {
        cout << *itr << endl;
    }
    return 0;
}
