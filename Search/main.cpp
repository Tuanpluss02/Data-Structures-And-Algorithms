#include "SearchAlgorithm.hpp"

int main()
{
    SearchAlgorithm<int> searcher;
    vector<int> arr;
    for (int i = 0; i < 1000000; ++i)
    {
        arr.push_back(i * 2);
    }
    int target = -1;

    // Ternary search recursion
    auto start = chrono::high_resolution_clock::now();
    int result1 = searcher.ternary_search_recursion(arr, target, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Ternary search recursion: " << result1 << "\n";
    cout << "Time taken: " << duration1.count() << " microseconds\n\n";

    // // Ternary search no recursion
    // start = chrono::high_resolution_clock::now();
    // int result2 = searcher.ternary_search_no_recursion(arr, target, 0, arr.size() - 1);
    // end = chrono::high_resolution_clock::now();
    // auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Ternary search no recursion: " << result2 << "\n";
    // cout << "Time taken: " << duration2.count() << " microseconds\n\n";

    // // Exponential search
    // start = chrono::high_resolution_clock::now();
    // int result3 = searcher.exponential_search(arr, target);
    // end = chrono::high_resolution_clock::now();
    // auto duration3 = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Exponential search: " << result3 << "\n";
    // cout << "Time taken: " << duration3.count() << " microseconds\n\n";

    // // Binary search recursion
    // start = chrono::high_resolution_clock::now();
    // int result4 = searcher.binary_search_recursion(arr, target, 0, arr.size() - 1);
    // end = chrono::high_resolution_clock::now();
    // auto duration4 = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Binary search recursion: " << result4 << "\n";
    // cout << "Time taken: " << duration4.count() << " microseconds\n\n";

    // // Binary search no recursion
    // start = chrono::high_resolution_clock::now();
    // int result5 = searcher.binary_search_no_recursion(arr, target, 0, arr.size() - 1);
    // end = chrono::high_resolution_clock::now();
    // auto duration5 = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Binary search no recursion: " << result5 << "\n";
    // cout << "Time taken: " << duration5.count() << " microseconds\n\n";

    // // Hashmap search
    // start = chrono::high_resolution_clock::now();
    // int result6 = searcher.hashmap_search(arr, target);
    // end = chrono::high_resolution_clock::now();
    // auto duration6 = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Hashmap search: " << result6 << "\n";
    // cout << "Time taken: " << duration6.count() << " microseconds\n\n";

    return 0;
}