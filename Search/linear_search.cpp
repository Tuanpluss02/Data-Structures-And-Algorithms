#include "SearchAlgorithm.hpp"

template <typename T>
long SearchAlgorithm<T>::linear_search(vector<T> &arr, T target)
{
    unordered_map<T, long> hashmap;
    for (long i = 0; i < arr.size(); i++)
    {
        hashmap[arr[i]] = i;
    }
    auto it = hashmap.find(target);
    if (it != hashmap.end())
    {
        return it->second;
    }
    return -1;
}