#include <bits/stdc++.h>
using namespace std;

template <typename T>
void heapify(vector<T> arr, long n, long i)
{
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
template <typename T>
void heap_sort(vector<T> arr, long n)
{
    for (long i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (long i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
