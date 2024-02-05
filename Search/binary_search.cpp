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
long binary_search_no_recursion(vector<T> &arr, T target, long start, long end)
{
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (start < 0 || end >= arr.size())
        throw invalid_argument("Start or end index is invalid!");
    while (start <= end)
    {
        long mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

template <typename T>
long binary_search_recursion(vector<T> &arr, T target, long start, long end)
{
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (start < 0 || end >= arr.size())
        throw invalid_argument("Start or end index is invalid!");
    if (start > end)
        return -1;
    long mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binary_search_recursion(arr, target, mid + 1, end);
    else
        return binary_search_recursion(arr, target, start, mid - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << endl;
    cout << binary_search_recursion(arr, 1, 0, arr.size() - 1) << endl;
    cout << binary_search_no_recursion(arr, 5, 0, arr.size() - 1) << endl;
    return 0;
}