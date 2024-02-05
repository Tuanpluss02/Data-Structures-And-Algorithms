#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BSTNode
{
    T data;
    BSTNode *left;
    BSTNode *right;
};

template <typename T>
BSTNode<T> *createNode(T value)
{
    BSTNode<T> *newNode = new BSTNode<T>();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

template <typename T>
BSTNode<T> *searchBST(BSTNode<T> *root, T value)
{
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return searchBST(root->left, value);

    return searchBST(root->right, value);
}

template <typename T>
BSTNode<T> *insertNode(BSTNode<T> *root, T value)
{
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

template <typename T>
BSTNode<T> *deleteNode(BSTNode<T> *root, T value)
{
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == nullptr)
        {
            BSTNode<T> *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            BSTNode<T> *temp = root->left;
            delete root;
            return temp;
        }

        BSTNode<T> *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

template <typename T>
BSTNode<T> *minValueNode(BSTNode<T> *node)
{
    BSTNode<T> *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
template <typename T>
BSTNode<T> *findMaxValue(BSTNode<T> *root)
{
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

template <typename T>
BSTNode<T> *findMinValue(BSTNode<T> *root)
{
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

template <typename T>
void inorderTraversal(BSTNode<T> *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
template <typename T>
int getHeight(BSTNode<T> *root)
{
    if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

template <typename T>
bool isBalanced(BSTNode<T> *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}
template <typename T>
BSTNode<T> *findParent(BSTNode<T> *root, T value)
{
    if (root == nullptr || root->data == value)
        return nullptr;

    BSTNode<T> *current = root;
    BSTNode<T> *parent = nullptr;

    while (current != nullptr)
    {
        if (value < current->data)
        {
            parent = current;
            current = current->left;
        }
        else if (value > current->data)
        {
            parent = current;
            current = current->right;
        }
        else
            break;
    }

    return parent;
}
int main()
{
    BSTNode<int> *root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    BSTNode<int> *maxNode = findMaxValue(root);
    BSTNode<int> *minNode = findMinValue(root);
    if (maxNode)
        cout << "Max value: " << maxNode->data << endl;
    if (minNode)
        cout << "Min value: " << minNode->data << endl;

    if (isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is not balanced." << endl;

    int value = 40;
    BSTNode<int> *parent = findParent(root, value);
    if (parent)
        cout << "Parent of " << value << ": " << parent->data << endl;
    else
        cout << "Parent of " << value << " not found." << endl;

    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "After deleting " << deleteValue << ", inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
