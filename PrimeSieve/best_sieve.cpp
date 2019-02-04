#include <iostream>
using namespace std;
#include <vector>

long *sieve1(long n)
{
#define MAXL (100000000 >> 5) + 1
#define GET(x) (mark[x >> 5] >> (x & 31) & 1)
#define SET(x) (mark[x >> 5] |= 1 << (x & 31))
    long prime[n + 5], idx = 0;
    static long mark[MAXL] = {};
    SET(1);
    for (long i = 2; i <= n; i++)
    {
        if (!GET(i))
        {
            for (long k = n / i, j = i * k; k >= i; k--, j -= i)
                SET(j);
            prime[idx++] = i;
        }
    }
    return prime;
}

std::vector<int> sieve2(int n)
{
    std::vector<int> prime;
    std::vector<int> mark(n + 1, 0); // Khởi tạo mảng mark với giá trị 0

    mark[1] = 1; // Đánh dấu số 1 là đã được sàng lọc (không phải số nguyên tố)

    for (int i = 2; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                mark[j] = 1; // Đánh dấu các bội của i là đã được sàng lọc
            }
            prime.push_back(i); // Lưu trữ số nguyên tố i vào vector prime
        }
    }

    return prime;
}

int main()
{
    long n = 100;
    long *prime = sieve1(n);
    for (long i = 0; i < n; i++)
    {
        cout << prime[i] << " ";
    }
}
