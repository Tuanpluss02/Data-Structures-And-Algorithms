#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK
};

template <typename T>
struct Node
{
    T data;
    Node *parent;
    Node *left;
    Node *right;
    Color color;

    Node(T value) : data(value), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

template <typename T>
class RedBlackTree
{
private:
    Node<T> *root;

    void leftRotate(Node<T> *x)
    {
        Node<T> *y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node<T> *y)
    {
        Node<T> *x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node<T> *z)
    {
        while (z->parent && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node<T> *y = z->parent->parent->right;
                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node<T> *y = z->parent->parent->left;
                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void insert(Node<T> *&root, Node<T> *z)
    {
        Node<T> *y = nullptr;
        Node<T> *x = root;

        while (x != nullptr)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        insertFixup(z);
    }

    void inorderTraversal(Node<T> *root)
    {
        if (root != nullptr)
        {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(T value)
    {
        Node<T> *z = new Node<T>(value);
        insert(root, z);
    }

    void printInorder()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main()
{
    RedBlackTree<int> rbTree;

    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(30);
    rbTree.insert(15);
    rbTree.insert(25);

    std::cout << "Inorder Traversal: ";
    rbTree.printInorder();

    return 0;
}
