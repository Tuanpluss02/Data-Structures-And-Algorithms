#include<bits/stdc++.h>
using namespace std;

template<typename T>
size_t binary_search_no_recursion(vector<T> &arr, T target) {
    size_t l = 0, r = arr.size() - 1;
    while(l <= r) {
        size_t mid = l + (r - l) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

template<typename T>
size_t binary_search_recursion(vector<T> &arr, T target, size_t l, size_t r) {
    if(l >= r) return -1;
    size_t mid = l + (r - l) / 2;
    cout << mid << endl;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return binary_search_recursion(arr, target, mid + 1, r);
    else return binary_search_recursion(arr, target, l, mid - 1);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << binary_search_recursion(arr, 9, 0, arr.size() - 1) << endl;
    // cout << binary_search_recursion(arr, 8) << endl;
    return 0;
}