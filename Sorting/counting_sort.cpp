#include <bits/stdc++.h>
using namespace std;

template <typename T>
void counting_sort(vector<T> &arr)
{
    T maxVal = *max_element(arr.begin(), arr.end());

    vector<T> count(maxVal + 1, 0);

    for (long i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
    }
    long index = 0;
    for (long i = 0; i <= maxVal; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}
