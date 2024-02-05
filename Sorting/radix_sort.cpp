#include "sort_algorithm.cpp"

template <typename T>
void radix_sort(std::vector<T> &arr)
{
    T max = *std::max_element(arr.begin(), arr.end());

    for (T exp = 1; max / exp > 0; exp *= 10)
    {
        std::vector<T> digits;
        for (int i = 0; i < arr.size(); ++i)
        {
            digits.push_back((arr[i] / exp) % 10);
        }

        counting_sort(digits);

        for (int i = 0; i < arr.size(); ++i)
        {
            arr[i] = digits[i];
        }
    }
}
