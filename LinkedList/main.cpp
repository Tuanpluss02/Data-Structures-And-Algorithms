#include "singlyLinkedList.h"
#include <iostream>
using namespace std;
int main()
{
    singlyLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.print();
    list.add(11, 1);
    list.print();
    list.add(22, 3);
    list.print();
    // cout << list.size() << endl;
    list.add(33, 7);
    list.print();
    list.remove(1);
    list.print();
    list.remove(7);
    list.print();
    list.remove(3);
    list.print();
    // system("pause");
    return 0;
}