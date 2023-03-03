def digitSum(n):
    return sum(map(int, str(n)))


def digitSumRange(n, m):
    if n > m:
        return 0
    d = digitSum(n)
    r = n % 9
    if r == 0:
        return d * (m - n + 1)
    count = (m // 9) - ((n-1) // 9)
    if n % 9 == 0:
        count += 1
    return d * count + digitSumRange(n+r+1, m) + digitSumRange(n, n+r)


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    print(digitSumRange(n, m))
