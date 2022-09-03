#ifndef __doublyLinkedList__StormX
#define __doublyLinkedList__StormX

#define ll long long

#include <iostream>

struct Node
{
    ll data;
    Node *next;
    Node *prev;
};

class doublyLinkedList
{
private:
    Node *head;
    Node *tail;
    size_t length;

public:
    doublyLinkedList();
    ~doublyLinkedList(); 
    size_t size();
    void add(ll data);
    void add(ll data, size_t position);
    void add(Node *node);
    void remove(size_t position);
    void printForward();
    void printBackward();
    void printNode(size_t position);
    void reverse();
    void sortDescending();
    void sortAscending();
};

doublyLinkedList::doublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
doublyLinkedList::~doublyLinkedList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}
size_t doublyLinkedList::size()
{
    return length;
}

void doublyLinkedList::add(ll dataInput)
{
    Node *newNode = new Node;
    newNode->data = dataInput;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}
// adds a node to the list at the given position.
void doublyLinkedList::add(ll dataInput, size_t position)
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

void doublyLinkedList::add(Node *node)
{
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    length++;
}

void doublyLinkedList::remove(size_t position)
{
    if (position > length || position <= 0)
    {
        std::cout << "Error: position is out of range." << std::endl;
        return;
    }
    if (position == 1)
    {
        head = head->next;
        head->prev = NULL;
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
        current->next->prev = previous;
    }
    delete current;
    length--;
}

void doublyLinkedList::printForward()
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

void doublyLinkedList::printBackward()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    size_t index = 0;
    Node *temp = tail;
    std::cout << "The list contains: " << std::endl;
    std::cout << "------------------------" << std::endl;
    while (temp != NULL)
    {
        std::cout << "Node " << length - index << ": " << temp->data << std::endl;
        temp = temp->prev;
        index++;
    }
    std::cout << "------------------------" << std::endl;
}

void doublyLinkedList::printNode(size_t position)
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

void doublyLinkedList::reverse()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        temp = temp2;
    }
    Node *temp3 = head;
    head = tail;
    tail = temp3;
}

void doublyLinkedList::sortAscending()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                ll tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void doublyLinkedList::sortDescending()
{
    if (length == 0)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data < temp2->data)
            {
                ll tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

#endif
