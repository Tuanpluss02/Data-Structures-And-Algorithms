#include <bits/stdc++.h>
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
    cout << binary_search_recursion(arr, 8, 0, arr.size() - 1) << endl;
    cout << binary_search_no_recursion(arr, 7, 0, arr.size() - 1) << endl;
    return 0;
}