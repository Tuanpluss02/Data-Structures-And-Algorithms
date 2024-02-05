#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    int height;
};

template <typename T>
int max(int a, int b)
{
    return (a > b) ? a : b;
}

template <typename T>
int height(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

template <typename T>
int getBalance(Node<T> *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template <typename T>
Node<T> *createNode(T data)
{
    Node<T> *newNode = new Node<T>();
    if (newNode == nullptr)
    {
        cout << "Memory allocation failed!" << endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

template <typename T>
Node<T> *rotateRight(Node<T> *y)
{
    Node<T> *x = y->left;
    Node<T> *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
Node<T> *rotateLeft(Node<T> *x)
{
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
Node<T> *insertNode(Node<T> *node, T data)
{
    if (node == nullptr)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
    {
        return rotateRight(node);
    }

    if (balance < -1 && data > node->right->data)
    {
        return rotateLeft(node);
    }

    if (balance > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

template <typename T>
void inorderTraversal(Node<T> *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    Node<int> *root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}