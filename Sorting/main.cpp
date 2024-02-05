#include "sort_algorithm.cpp"
#include <chrono>
#include <random>
#include <algorithm>
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
    const long VECTOR_SIZE = 5000;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<long> distribution(0, 100000);
    vector<long> arr(VECTOR_SIZE);
    for (int i = 0; i < VECTOR_SIZE; ++i)
    {
        arr[i] = distribution(generator);
    }
    vector<long> arrT = arr;
    cout << "Vector size: " << arr.size();
    cout << "\n\n";

    vector<pair<string, chrono::microseconds>> sortDurations;

    auto start = chrono::high_resolution_clock::now();
    bubble_sort(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Bubble sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    insertion_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Insertion sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    selection_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Selection sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    merge_sort(arr, 0, arr.size());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Merge sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    heap_sort(arr, arr.size());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Heap sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    counting_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Counting sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    tim_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Tim sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    radix_sort(arr);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Radix sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    quick_sort(arr, 0, arr.size());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"Quick sort", duration});

    arr = arrT;
    start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end(), greater<long>());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    sortDurations.push_back({"STL sort", duration});

    sort(sortDurations.begin(), sortDurations.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    for (const auto &sortDuration : sortDurations)
    {
        cout << sortDuration.first << ": " << sortDuration.second.count() << " microseconds\n";
    }

    return 0;
}