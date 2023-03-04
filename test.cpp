#include <iostream>
#include <vector>
using namespace std;

void parseNumber(int n, vector<int> &numbers)
{
    if (n == 1)
    {
        numbers.push_back(1);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        numbers.push_back(i);
        parseNumber(n - i, numbers);
    }
}

int main()
{
    int n;
    // cout << "Enter a positive integer: ";
    cin >> n;

    vector<int> numbers;
    parseNumber(n, numbers);

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << "(" << numbers[i] << ")";
    }
    cout << endl;

    return 0;
}
