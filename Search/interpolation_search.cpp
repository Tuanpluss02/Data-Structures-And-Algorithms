#include "SearchAlgorithm.hpp"

template <typename T>
long SearchAlgorithm<T>::interpolation_search(vector<T> &arr, T target, long start, long end)
{
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (start < 0 || end >= arr.size())
        throw invalid_argument("Start or end index is invalid!");
    long mid;
    while (arr[end] != arr[start] && target >= arr[start] && target <= arr[end])
    {
        mid = start + ((target - arr[start]) * (end - start) / (arr[end] - arr[start]));
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (arr[start] == target)
        return start;
    return -1;
}
