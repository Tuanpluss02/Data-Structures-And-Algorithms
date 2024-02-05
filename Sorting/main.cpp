#include "sort_algorithm.cpp"
#include <chrono>
#include <random>
using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &arr)
{
    for_each(arr.begin(), arr.end(), [&os](const auto &element)
             { os << element << " "; });
    return os;
}

int main()
{
    const long VECTOR_SIZE = 10000;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<long> distribution(0, 1000);
    vector<long> arr(VECTOR_SIZE);
    for (int i = 0; i < VECTOR_SIZE; ++i)
    {
        arr[i] = distribution(generator);
    }
    vector<long> arrT = arr;
    cout << "Vector size: " << arr.size();
    cout << "\n\n";

    auto start = chrono::high_resolution_clock::now();
    bubble_sort(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Bubble sort:  " << duration.count() << " microseconds\n";

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    insertion_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Insertion sort: " << duration.count() << " microseconds\n";

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    merge_sort(arr, 0, arr.size());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Merge sort: " << duration.count() << " microseconds\n";

    return 0;
}