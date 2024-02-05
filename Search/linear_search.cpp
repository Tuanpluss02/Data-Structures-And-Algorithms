#include <bits/stdc++.h>
using namespace std;

template <typename T>
long linear_search(vector<T> &arr, T target)
{
    for (long i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}