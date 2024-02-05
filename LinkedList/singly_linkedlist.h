#ifndef __singlyLinkedList__StormX
#define __singlyLinkedList__StormX

#define ll long long

#include <iostream>

struct Node
{
    ll data;
    Node *next;
};

class singlyLinkedList
{
private:
    Node *head;
    Node *tail;
    size_t length;

public:
    singlyLinkedList();
    ~singlyLinkedList();
    void add(ll data);
    void add(ll data, size_t position);
    void add(Node *node);
    void remove(size_t position);
    void print();
    void print(size_t position);
    size_t size();
    void sort();
};
// Constructor
singlyLinkedList::singlyLinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}
// Destructor
singlyLinkedList::~singlyLinkedList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

// return the size of the list
size_t singlyLinkedList::size()
{
    return length;
}

// Add a node to the end of the list.
void singlyLinkedList::add(ll dataInput)
{
    Node *newNode = new Node;
    newNode->data = dataInput;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}
// adds a node to the list at the given position.
void singlyLinkedList::add(ll dataInput, size_t position)
{
    if (length == 0)
    {
        add(dataInput);
        return;
    }
    if (position > length || position < 0)
    {
        std::cout << "Error: position is out of range." << std::endl;
        return;
    }
    Node *previous = head;
    Node *current = head;
    Node *newNode = new Node;
    newNode->data = dataInput;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        length++;
        return;
    }
    while (position--)
    {
        if (position == 0)
        {
            newNode->next = current;
            previous->next = newNode;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    length++;
}

void singlyLinkedList::add(Node *node)
{
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    length++;
}

void singlyLinkedList::remove(size_t position)
{
    if (position > length || position <= 0)
    {
        std::cout << "Error: position is out of range." << std::endl;
        return;
    }
    if (position == 1)
    {
        head = head->next;
        length--;
        return;
    }
    Node *current = head;
    Node *previous = head;
    while (position-- > 1)
    {
        previous = current;
        current = current->next;
        if (current == tail)
            break;
    }
    if (current == tail)
    {
        previous->next = NULL;
        tail = previous;
    }
    else
    {
        previous->next = current->next;
    }
    delete current;
    length--;
}

void singlyLinkedList::print()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    size_t index = 0;
    Node *temp = head;
    std::cout << "The list contains: " << std::endl;
    std::cout << "------------------------" << std::endl;
    while (temp != NULL)
    {
        std::cout << "Node " << index + 1 << ": " << temp->data << std::endl;
        temp = temp->next;
        index++;
    }
    std::cout << "------------------------" << std::endl;
}

void singlyLinkedList::print(size_t position)
{
    if (position > length || position <= 0)
    {
        std::cout << "Error: position is out of range." << std::endl;
        return;
    }
    Node *temp = head;
    std::cout << "------------------------" << std::endl;
    for (size_t i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    std::cout << "Node " << position << ": " << temp->data << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Swap(Node *a, Node *b)
{
    ll temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void singlyLinkedList::sort()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *current = temp;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                ll temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
        temp = temp->next;
    }
}

void singlyLinkedList::sort()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *current = temp;
        while (current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                ll temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
        temp = temp->next;
    }
}
#endif