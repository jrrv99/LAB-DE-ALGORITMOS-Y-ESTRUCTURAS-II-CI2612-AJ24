#include <iostream>
#include <vector>

using namespace std;

void ripple_sort(vector<int> &arr)
{
    int key; // aux
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                key = arr[i];
                arr[i] = arr[j];
                arr[j] = key;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 1, 9, 3, 8};
    //
    // i = 0, j = 1 [4, 1, 9, 3, 8]
    //      (j = 1) | arr[0] > arr[1] | 4 > 1 => swap(4, 1) => {1, 4, 9, 3, 8}
    //      (j = 2) | arr[0] > arr[2] | 1 > 9 => {1, 4, 9, 3, 8}
    //      (j = 3) | arr[0] > arr[2] | 1 > 3 => {1, 4, 9, 3, 8}
    //      (j = 4) | arr[0] > arr[2] | 1 > 8 => {1, 4, 9, 3, 8}
    // i = 1 | j = 2 | [1, 4, 9, 3, 8]
    //      (j = 2) | arr[1] > arr[2] | 4 > 9 => [1, 4, 9, 3, 8]
    //      (j = 3) | arr[1] > arr[3] | 4 > 3 => swap(4, 3) => [1, 3, 9, 4, 8]
    //      (j = 4) | arr[1] > arr[4] | 3 > 8 => [1, 3, 9, 4, 8]
    // i = 2 | j = 3 | [1, 3, 9, 4, 8]
    //      (j = 3) | arr[2] > arr[3] === 9 > 4 => swap(9, 4) => [1, 3, 4, 9, 8]
    //      (j = 4) | arr[2] > arr[4] === 4 > 8 => [1, 3, 4, 9, 8]
    // i = 3 | j = 4 | [1, 3, 4, 9, 8]
    //      (j = 4) | arr[3] > arr[4] === 9 > 8 => swap(9, 8) [1, 3, 4, 8, 9]
    // i = 4 | j = 5 | [1, 3, 4, 8, 9]
    //      skip (5 < 4)
    // [1, 3, 4, 9, 8]

    ripple_sort(arr);

    for (auto &&i : arr)
    {
        printf("%d ", i);
    }

    cout << endl
         << 5 / 2 << endl;

    return 0;
}
