#include <bits/stdc++.h>
using namespace std;

template <typename T>
void merge(vector<T> &arr, long start, long mid, long end)
{
    vector<T> tempArr(end - start + 1);
    long i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            tempArr[k++] = arr[i++];
        else
            tempArr[k++] = arr[j++];
    }

    while (i <= mid)
        tempArr[k++] = arr[i++];
    while (j <= end)
        tempArr[k++] = arr[j++];

    for (int p = 0; p < k; ++p)
        arr[start + p] = tempArr[p];
}

template <typename T>
void merge_sort(vector<T> &arr, long start, long end)
{
    if (start < end)
    {
        long mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}