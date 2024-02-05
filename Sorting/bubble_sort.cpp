#include <bits/stdc++.h>
using namespace std;

template <typename T>
void bubble_sort(vector<T> &arr)
{
    long size = arr.size();
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    for (long i = 0; i < size - 1; ++i)
    {
        for (long j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}