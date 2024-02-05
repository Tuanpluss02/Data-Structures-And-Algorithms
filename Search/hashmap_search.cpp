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
long hashmap_search(vector<T> arr, T target)
{
    unordered_map<T, long> hashmap;
    for (long i = 0; i < arr.size(); i++)
    {
        hashmap[arr[i]] = i;
    }
    auto it = hashmap.find(target);
    if (it != hashmap.end())
    {
        return it->second;
    }

    return -1;
}

int main()
{
    faster();
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 3;
    cout << hashmap_search(arr, target);
    return 0;
}
