#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of the last element smaller than the pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]); // Swap the current element with the element at i
        }
    }

    swap(arr[i + 1], arr[high]); // Swap the pivot with the element at i + 1

    return i + 1; // Return the new pivot index
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Sort the left subarray
        quickSort(arr, pivotIndex + 1, high); // Sort the right subarray
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4, 1, 9, 3, 8};

    quickSort(arr, 0, arr.size() - 1);

    for (auto &&i : arr)
    {
        printf("%d ", i);
    }

    return 0;
}
