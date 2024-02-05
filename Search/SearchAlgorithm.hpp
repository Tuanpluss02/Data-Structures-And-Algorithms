#ifndef SEARCH_ALGORITHM_H
#define SEARCH_ALGORITHM_H

#include <bits/stdc++.h>

#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define clean() cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define pb push_back
#define fi first
#define se second
#define Mod 1000000007
#define ld long double
#define ll long long
#define lli unsigned long long int
#define For(i, a, b) for (ll i = a; i < b; ++i)
#define Forr(i, a, b) for (ll i = a; i >= b; --i)
#define vec vector<ll>
#define sortu(c) sort(c.begin(), c.end())
#define sortd(c) sort(c.rbegin(), c.rend())
#define rev(c) reverse(c.begin(), c.end())
#define pause() system("pause");
using namespace std;

template <typename T>
class SearchAlgorithm
{
public:
    long binary_search_recursion(vector<T> &arr, T target, long start, long end);
    long binary_search_no_recursion(vector<T> &arr, T target, long start, long end);
    long fibonacci_search_type1(vector<T> &arr, T target);
    long fibonacci_search_type2(vector<T> &arr, T target);
    long interpolation_search(vector<T> &arr, T target, long start, long end);
    long linear_search(vector<T> &arr, T target);
    long ternary_search_recursion(vector<T> &arr, T target, long start, long end);
    long ternary_search_no_recursion(vector<T> &arr, T target, long start, long end);
    long exponential_search(vector<T> &arr, T target);
};

#endif