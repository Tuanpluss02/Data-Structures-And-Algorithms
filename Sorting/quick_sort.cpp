#include <bits/stdc++.h>
using namespace std;

template <typename T>
long partition(vector<T> arr, long start, long end)
{
    T pivot = arr[end];
    long index = start - 1;
    for (long j = start; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            swap(arr[index], arr[j]);
        }
    }
    swap(arr[index + 1], arr[end]);
    return index + 1;
}

template <typename T>
void quick_sort(vector<T> arr, long start, long end)
{
    if (start < end)
    {
        long index = partition(arr, start, end);
        quick_sort(arr, start, index - 1);
        quick_sort(arr, index + 1, end);
    }
}