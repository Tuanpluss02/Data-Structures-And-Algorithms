#include "sort_algorithm.cpp"

template <typename T>
void bucket_sort(vector<T> &arr, long numBuckets)
{
    vector<vector<T>> buckets(numBuckets);

    T minValue = *min_element(arr.begin(), arr.end());
    T maxValue = *max_element(arr.begin(), arr.end());

    float range = (maxValue - minValue + 1) / static_cast<float>(numBuckets);

    for (long i = 0; i < arr.size(); ++i)
    {
        long bucketIndex = static_cast<long>((arr[i] - minValue) / range);
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (long i = 0; i < numBuckets; ++i)
    {
        counting_sort(buckets[i]);
    }

    long index = 0;
    for (long i = 0; i < numBuckets; ++i)
    {
        for (long j = 0; j < buckets[i].size(); ++j)
        {
            arr[index++] = buckets[i][j];
        }
    }
}