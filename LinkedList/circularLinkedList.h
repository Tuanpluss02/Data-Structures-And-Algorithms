#ifndef __circularLinkedList__StormX
#define __circularLinkedList__StormX

#define ll long long
#include <iostream>

struct Node
{
    ll data;
    Node *next;
    Node *prev;
};

class circularLinkedList
{
private:
    Node *head;
    Node *tail;
    size_t length;

public:
    circularLinkedList();
    ~circularLinkedList();
    size_t size();
    void add(ll data);
    void add(ll data, size_t position);
    void add(Node *node);
    void remove(size_t position);
    void print();
    void print(size_t position);
};

circularLinkedList::circularLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
circularLinkedList::~circularLinkedList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
size_t circularLinkedList::size()
{
    return length;
}
void circularLinkedList::add(ll dataInput)
{
    Node *node = new Node;
    node->data = dataInput;
    node->next = nullptr;
    node->prev = nullptr;
    if (head == nullptr)
    {
        head = node;
        tail = node;
        node->next = head;
        node->prev = tail;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = head;
        head->prev = tail;
    }
    length++;
}

// adds a node to the list at the given position.
void circularLinkedList::add(ll dataInput, size_t position)
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
    newNode->prev = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = tail;
        length++;
        return;
    }
    while (position--)
    {
        if (position == 0)
        {
            newNode->next = current;
            current->prev = newNode;
            previous->next = newNode;
            newNode->prev = previous;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    length++;
}

void circularLinkedList::add(Node *node)
{
    if (head == NULL)
    {
        head = node;
        tail = node;
        node->next = tail;
        node->prev = head;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = head;
        head->prev = tail;
    }
    length++;
}

void circularLinkedList::remove(size_t position)
{
    if (position > length || position <= 0)
    {
        std::cout << "Error: position is out of range." << std::endl;
        return;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
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
        tail = previous;
        tail->next = head;
        head->prev = tail;
        delete current;
        length--;
        return;
    }
    else
    {
        previous->next = current->next;
        current->next->prev = previous;
    }
    delete current;
    length--;
}

void circularLinkedList::print()
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
    while (temp != tail)
    {
        std::cout << "Node " << index + 1 << ": " << temp->data << std::endl;
        temp = temp->next;
        index++;
    }
    std::cout << "Node " << index + 1 << ": " << temp->data << std::endl;
    std::cout << "------------------------" << std::endl;
}
// print the node at given position
void circularLinkedList::print(size_t position)
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

#endif