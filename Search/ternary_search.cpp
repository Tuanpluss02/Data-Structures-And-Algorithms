#include "SearchAlgorithm.hpp"

template <typename T>
long SearchAlgorithm<T>::ternary_search_recursion(vector<T> &arr, T target, long start, long end)
{
    long size = arr.size();
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (start < 0 || end >= size)
        throw invalid_argument("Start or end index is invalid!");
    if (end < start || end < 0)
        return -1;
    long mid1 = start + (end - start) / 3;
    long mid2 = end - (end - start) / 3;
    if (arr[mid1] == target)
        return mid1;
    if (arr[mid2] == target)
        return mid2;

    if (target < arr[mid1])
        return ternary_search_recursion(arr, target, start, mid1 - 1);
    else if (target > arr[mid2])
        return ternary_search_recursion(arr, target, mid2 + 1, end);
    else
        return ternary_search_recursion(arr, target, mid1 + 1, mid2 - 1);
    return -1;
}

template <typename T>
long SearchAlgorithm<T>::ternary_search_no_recursion(vector<T> &arr, T target, long start, long end)
{
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (start < 0 || end >= arr.size())
        throw invalid_argument("Start or end index is invalid!");
    while (end >= start)
    {
        long mid1 = start + (end - start) / 3;
        long mid2 = end - (end - start) / 3;
        if (arr[mid1] == target)
            return mid1;
        if (arr[mid2] == target)
            return mid2;

        if (target < arr[mid1])
            end = mid1 - 1;
        else if (target > arr[mid2])
            start = mid2 + 1;
        else
        {
            start = mid1 + 1;
            end = mid2 - 1;
        }
    }
    return -1;
}
