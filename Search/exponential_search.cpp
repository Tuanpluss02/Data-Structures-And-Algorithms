#include "SearchAlgorithm.hpp"

template <typename T>
long SearchAlgorithm<T>::exponential_search(vector<T> &arr, T target)
{
    long size = arr.size();
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    if (size == 1)
        return arr[0] == target ? 0 : -1;
    long bound = 1;
    while (bound < size && arr[bound] <= target)
    {
        bound *= 2;
    }
    return binary_search_no_recursion(arr, target, bound / 2, min(bound, size - 1));
}
