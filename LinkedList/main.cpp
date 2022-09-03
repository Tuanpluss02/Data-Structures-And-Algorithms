#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
#include <iostream>
using namespace std;
int main()
{
    doublyLinkedList list;
    list.add(56);
    list.add(32);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(100, 2);
    list.printForward();
    list.remove(2);
    list.printForward();
    list.reverse();
    list.printForward();
    list.sortAscending();
    list.printForward();
    list.sortDescending();
    list.printForward();
    // list.sort();
    // list.print();
    // system("pause");
    return 0;
}