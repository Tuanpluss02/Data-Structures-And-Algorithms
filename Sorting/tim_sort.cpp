#include "sort_algorithm.cpp"

template <typename T>
void tim_sort(vector<T> &arr)
{
    long n = arr.size();
    long RUN = 32;

    while (RUN < n)
    {
        RUN = (RUN << 1) + 1;
    }
    RUN = min(RUN, n);

    for (long i = 0; i < n; i += RUN)
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1)));

    for (long size = RUN; size < n; size = 2 * size)
    {
        for (long left = 0; left < n; left += 2 * size)
        {
            long mid = left + size - 1;
            long right = min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}
