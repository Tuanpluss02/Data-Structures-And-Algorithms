#include <bits/stdc++.h>
using namespace std;

template <typename T>
void selection_sort(vector<T> arr)
{
    long size = arr.size();
    for (long i = 0; i < size - 1; i++)
    {
        long minIndex = i;
        for (long j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}