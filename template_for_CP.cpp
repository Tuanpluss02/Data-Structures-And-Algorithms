#include <bits/stdc++.h>

#define faster()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define clear() cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define pb push_back
#define fi first
#define se second
#define Mod 1000000007
#define ld long double
#define ll long long
#define lli unsigned long long int
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Forr(i, a, b) for (int i = a; i >= b; --i)
#define vec vector<ll>
#define sortu(c) sort(c.begin(), c.end())
#define sortd(c) sort(c.rbegin(), c.rend())
#define rev(c) reverse(c.begin(), c.end())
#define pause() system("pause");
using namespace std;

// some extra functions
int prime[5800000], idx = 0;
void sieve()
{
#define MAXL (100000000 >> 5) + 1
#define GET(x) (mark[x >> 5] >> (x & 31) & 1)
#define SET(x) (mark[x >> 5] |= 1 << (x & 31))
    static int mark[MAXL] = {};
    SET(1);
    int n = 100000000;
    for (int i = 2; i <= n; i++)
    {
        if (!GET(i))
        {
            for (int k = n / i, j = i * k; k >= i; k--, j -= i)
                SET(j);
            prime[idx++] = i;
        }
    }
}

ll power(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

class BigInt
{
public:
    string num;
    BigInt() {}
    BigInt(string n)
    {
        this->num = n;
    }
    BigInt(char n)
    {
        this->num = string(1, n);
    }
    ~BigInt() {}
    bool operator>(BigInt b)
    {
        if (num.length() > b.num.length())
            return true;
        else if (num.length() < b.num.length())
            return false;
        else
            return num > b.num;
    }
    bool operator>=(BigInt b)
    {
        if (num.length() >= b.num.length())
            return true;
        else if (num.length() < b.num.length())
            return false;
        else
            return num >= b.num;
    }
    BigInt operator+(BigInt x)
    {
        BigInt c;
        int carry = 0;
        for (int i = num.length() - 1, j = x.num.length() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int a = (i >= 0) ? num[i] - '0' : 0;
            int b = (j >= 0) ? x.num[j] - '0' : 0;
            int sum = a + b + carry;
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
                carry = 0;
            c.num = to_string(sum) + c.num;
        }
        if (carry == 1)
            c.num = "1" + c.num;
        return c;
    }
    BigInt operator-(BigInt x)
    {
        bool reg = false;
        BigInt m = x;
        BigInt n = *this;
        if (m > n)
        {
            reg = true;
            swap(m.num, n.num);
        }
        BigInt res;
        int carry = 0;
        for (int i = n.num.length() - 1, j = m.num.length() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int a = (i >= 0) ? n.num[i] - '0' : 0;
            int b = (j >= 0) ? m.num[j] - '0' : 0;
            int sub = a - b - carry;
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;
            res.num = to_string(sub) + res.num;
        }
        while (res.num[0] == '0' && res.num.length() > 1)
        {
            res.num.erase(0, 1);
        }
        if (reg)
        {
            res.num = "-" + res.num;
        }
        return res;
    }
    BigInt operator*(BigInt x)
    {
        BigInt res;
        int carry = 0;
        for (int i = num.length() - 1; i >= 0; i--)
        {
            BigInt temp;
            int a = num[i] - '0';
            int b = 0;
            for (int j = x.num.length() - 1; j >= 0; j--)
            {
                b = x.num[j] - '0';
                int mul = a * b + carry;
                if (mul >= 10)
                {
                    carry = mul / 10;
                    mul = mul % 10;
                }
                else
                    carry = 0;
                temp.num = to_string(mul) + temp.num;
            }
            if (carry > 0)
            {
                temp.num = to_string(carry) + temp.num;
                carry = 0;
            }
            for (int k = num.length() - 1; k > i; k--)
            {
                temp.num = temp.num + "0";
            }
            res = res + temp;
        }
        while (res.num[0] == '0' && res.num.length() > 1)
        {
            res.num.erase(0, 1);
        }
        return res;
    }
    BigInt operator/(BigInt x)
    {
        BigInt res;
        BigInt temp;
        for (int i = 0; i < num.length(); i++)
        {
            temp.num = temp.num + num[i];
            int count = 0;
            while (temp >= x)
            {
                temp = temp - x;
                count++;
            }
            res.num = res.num + to_string(count);
        }
        while (res.num[0] == '0' && res.num.length() > 1)
        {
            res.num.erase(0, 1);
        }
        return res;
    }
    BigInt operator%(BigInt x)
    {
        BigInt res;
        BigInt temp;
        for (int i = 0; i < num.length(); i++)
        {
            temp.num = temp.num + num[i];
            int count = 0;
            while (temp >= x)
            {
                temp = temp - x;
                count++;
            }
            res.num = res.num + to_string(count);
        }
        while (res.num[0] == '0' && res.num.length() > 1)
        {
            res.num.erase(0, 1);
        }
        return temp;
    }
    BigInt power(BigInt x)
    {
        BigInt res = 1;
        BigInt a = *this;
        while (x.num != "0")
        {
            if (x.num.back() % 2 == 1)
                res = res * a;
            a = a * a;
            x = x / 2;
        }
        return res;
    }
};
ostream &operator<<(ostream &out, const BigInt &x) { return out << x.num; }
istream &operator>>(istream &in, BigInt &x) { return in >> x.num; }

struct Mint
{
    ll MOD = 1e9 + 7;
    ll val;
    bool operator==(const Mint &other) { return val == other.val; }
    Mint operator+(const Mint &other)
    {
        ll res = val + other.val;
        while (res >= MOD)
            res -= MOD;
        while (res < 0)
            res += MOD;
        return Mint(res);
    }
    Mint operator-(const Mint &other)
    {
        ll res = val - other.val;
        while (res >= MOD)
            res -= MOD;
        while (res < 0)
            res += MOD;
        return Mint(res);
    }
    Mint operator*(const Mint &other) { return Mint((val * 1ll * other.val) % MOD); }
    Mint operator+=(const Mint &other)
    {
        val += other.val;
        while (val >= MOD)
            val -= MOD;
        while (val < 0)
            val += MOD;
        return val;
    }
    Mint operator-=(const Mint &other)
    {
        val -= other.val;
        while (val >= MOD)
            val -= MOD;
        while (val < 0)
            val += MOD;
        return val;
    }
    Mint operator*=(const Mint &other) { return val = (val * 1ll * other.val) % MOD; }
    Mint pow(ll y)
    {
        Mint z(1);
        Mint x(val);
        while (y)
        {
            if (y & 1)
                z = (z * x);
            x = (x * x);
            y >>= 1;
        }
        return z;
    }
    Mint operator/(const Mint &other) { return Mint(val) * Mint(other.val).pow(MOD - 2); }
    Mint() { val = 0; };
    Mint(ll x)
    {
        x %= MOD;
        while (x < 0)
            x += MOD;
        val = x;
    };
};
ostream &operator<<(ostream &out, const Mint &x) { return out << x.val; }

// Main code

void solve()
{
    BigInt a, b;
    cin >> a >> b;
    cout << a.power(b) << endl;
}

int main()
{
    faster();
    sieve();
    int test = 1;
    cin >> test;
    // clear();
    while (test--)
    {
        solve();
    }
    // pause();
    return 0;
}
