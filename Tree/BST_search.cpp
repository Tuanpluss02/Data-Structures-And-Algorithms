#include <bits/stdc++.h>

#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define clean() cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define pb push_back
#define fi first
#define se second
#define Mod 1000000007
#define ld long double
#define ll long long
#define lli unsigned long long int
#define For(i, a, b) for (ll i = a; i < b; ++i)
#define Forr(i, a, b) for (ll i = a; i >= b; --i)
#define vec vector<ll>
#define sortu(c) sort(c.begin(), c.end())
#define sortd(c) sort(c.rbegin(), c.rend())
#define rev(c) reverse(c.begin(), c.end())
#define pause() system("pause");

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
};

template <typename T>
Node<T> *createNode(T value)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

template <typename T>
Node<T> *searchBST(Node<T> *root, T value)
{
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return searchBST(root->left, value);

    return searchBST(root->right, value);
}

int main()
{
    Node<int> *root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    int searchValue = 4;
    Node<int> *result = searchBST(root, searchValue);
    if (result != nullptr)
        cout << "Value found: " << result->data << " at address: " << result << endl;
    else
        cout << "Value not found!";

    return 0;
}
