#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;


int main(){
    DoublyLinkedList<int> dll;
    dll.push(1);
    dll.push(2);
    dll.push(30);
    dll.insert(4, 1);
    dll.remove(2);
    dll.print();
    dll.at(-1);
    dll.at(3);
    cout << dll.size() << endl;
    dll.print();
    return 0;
}