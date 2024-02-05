// #include "singlyLinkedList.h"
// #include "doublyLinkedList.h"
#include "circular_linkedlist.h"
#include <iostream>
using namespace std;
int main()
{
    // test singly linked list
    // cout << "Singly Linked List:" << endl;
    // singlyLinkedList list1;
    // list1.add(3);
    // list1.add(4);
    // list1.add(5);
    // list1.add(1);
    // list1.add(2);
    // list1.print();
    // list1.remove(3);
    // list1.print();
    // list1.remove(1);
    // list1.print();
    // list1.add(200);
    // list1.add(100, 2);
    // list1.print();
    // list1.sort();
    // list1.print();
    // cout << "The length of the list is " << list1.size() << endl;

    // // test doubly linked list
    // cout << "Doubly Linked List:" << endl;
    // doublyLinkedList list2;
    // list2.add(3);
    // list2.add(4);
    // list2.add(5);
    // list2.add(1);
    // list2.add(2);
    // list2.printForward();
    // list2.remove(3);
    // list2.printForward();
    // list2.remove(1);
    // list2.printForward();
    // list2.add(200);
    // list2.add(100, 2);
    // list2.add(-20, 4);
    // list2.printForward();
    // list2.sortAscending();
    // list2.printForward();
    // list2.sortDescending();
    // list2.printForward();
    // list2.printBackward();
    // cout << "The length of the list is " << list2.size() << endl;

    // test circular linked list
    cout << "Circular Linked List:" << endl;
    circularLinkedList list3;
    list3.add(3);
    list3.add(4);
    list3.add(5);
    list3.add(1);
    list3.add(2);
    list3.print();
    list3.remove(3);
    list3.print();
    list3.remove(1);
    list3.print();
    list3.add(200);
    list3.add(100, 2);
    list3.add(-20, 4);
    list3.print(2);
    list3.print();
    cout << "The length of the list is " << list3.size() << endl;
    // system("pause");
    return 0;
}