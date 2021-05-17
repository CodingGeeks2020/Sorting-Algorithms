#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void radix_sort(vector<int>& input_array)
{
    int max_elem = *max_element(input_array.begin(), input_array.end());

    int times_run = 0;
    while (max_elem > 0)
    {
        times_run++;
        max_elem /= 10;
    }

    vector<vector<int>> buckets(10);
    int divisor = 1;

    while (times_run--)
    {
        for (int i : input_array)
        {
            int column = int(i / divisor) % 10;
            buckets[column].push_back(i);
        }

        input_array.clear();

        for (vector<int>& single_bucket : buckets)
        {
            for (int i : single_bucket)
            {
                input_array.push_back(i);
            }

            single_bucket.clear();
        }

        divisor *= 10;
    }
}


int main()
{
    vector<int> arr{ 5,4,1,3,2};

    radix_sort(arr);

    for (int i : arr)
        cout << i << " ";
}