#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &numbers)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (numbers[i] < numbers[i - 1])
            {
                swap(numbers[i - 1], numbers[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 1, 9, 3, 8};

    bubbleSort(arr);

    for (auto &&i : arr)
    {
        printf("%d ", i);
    }

    return 0;
}