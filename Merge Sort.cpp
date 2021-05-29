#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> merged(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> final;

    int i = 0;
    int j = 0;

    while (i < arr1.size() or j < arr2.size())
    {
        if (i < arr1.size() and j < arr2.size())
        {
            if (arr1[i] > arr2[j])
            {
                final.push_back(arr2[j]);
                j++;
            }
            else
            {
                final.push_back(arr1[i]);
                i++;
            }
        }

        else if (i < arr1.size())
        {
            final.push_back(arr1[i]);
            i++;
        }

        else
        {
            final.push_back(arr2[j]);
            j++;
        }
    }
    return final;
}


vector<int> mergesort(vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return arr;

    vector<int> arr1(arr.begin(), arr.begin() + n / 2);
    vector<int> arr2(arr.begin() + n / 2, arr.end());

    arr1 = mergesort(arr1);



    arr2 = mergesort(arr2);

    return merged(arr1, arr2);
}


int main()
{
    vector<int> arr{ 1,3,2,5,4 };
    for (int i : mergesort(arr))
        cout << i << " ";
}