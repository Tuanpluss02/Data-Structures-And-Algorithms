#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insertion_sort(vector<T> &arr)
{
    long i, j, key, n = arr.size();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}