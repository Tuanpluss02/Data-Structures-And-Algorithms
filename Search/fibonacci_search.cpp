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
long fibonacci_search_type1(vector<T> &arr, long target)
{
    if (arr.empty())
        throw invalid_argument("Vector is empty!");
    long off = -1, fib2 = 0, fib1 = 1, fibm = fib1 + fib2, index;
    long n = arr.size();
    while (fibm < n)
    {
        fib2 = fib1;
        fib1 = fibm;
        fibm = fib1 + fib2;
    }
    while (fibm > 1)
    {
        index = min(off + fib2, n - 1);
        if (arr[index] < target)
        {
            fibm = fib1;
            fib1 = fib2;
            fib2 = fibm - fib1;
            off = index;
        }
        else if (arr[index] > target)
        {
            fibm = fib2;
            fib1 = fib1 - fib2;
            fibm = fibm - fib1;
        }
        else
            return index;
    }
    if (fib1 && arr[off + 1] == target)
        return off + 1;
    return -1;
}

void generateFibonacci(vector<long> &fib, long maxSize)
{
    fib.push_back(0);
    fib.push_back(1);

    while (fib.back() < maxSize)
    {
        long nextFib = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(nextFib);
    }
}

template <typename T>
long fibonacci_search_type2(vector<T> arr, T target)
{
    long n = arr.size();
    vector<long> fib;
    generateFibonacci(fib, 40);
    long offset = -1, i;
    for (i = 0; fib[i] < n; ++i)
        ;
    while (i > 0)
    {
        long index = min(offset + fib[i - 1], n - 1);
        if (arr[index] > target)
            --i;
        else if (arr[index] < target)
            offset = index, i -= 2;
        else
            return index;
    }

    return -1;
}

int main()
{
    faster();
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << fibonacci_search_type1(arr, 4) << endl;
    cout << fibonacci_search_type2(arr, 5) << endl;
    return 0;
}
