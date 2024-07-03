#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void merge(vector<int> &arr, vector<int> &left, vector<int> &right)
{

    int i = 0, j = 0, k = 0; // Index pointers

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++]; // Copy left element to the merged array
        }
        else
        {
            arr[k++] = right[j++]; // Copy right element to the merged array
        }
    }

    // Copy remaining elements from the left or right subarray, if any
    while (i < left.size())
    {
        arr[k++] = left[i++];
    }
    while (j < right.size())
    {
        arr[k++] = right[j++];
    }
}

void merge2(vector<int> &arr, vector<int> &left, vector<int> &right)
{
    int i = 0, j = 0, k = 0;                   // Index pointers
    int arr_sise = left.size() + right.size(); // n + m

    left.push_back(numeric_limits<int>::max());
    right.push_back(numeric_limits<int>::max());

    while (k < arr_sise)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++]; // Copy left element to the merged array
        }
        else
        {
            arr[k++] = right[j++]; // Copy right element to the merged array
        }
    }
}

void mergePalma(vector<int> &arr, vector<int> &left, vector<int> &right)
{
    int i = 0, j = 0, k = 0; // Index pointers

    int arr_lenght = left.size() + right.size();

    // sentries
    left.push_back(numeric_limits<int>::max());
    right.push_back(numeric_limits<int>::max());

    for (int k = 0; k < arr_lenght; k++)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i++];
            // i++;
        }
        else
        {
            arr[k] = right[j++];
            // j++;
        }
    }
}

void mergeSort(vector<int> &arr)
{
    if (arr.size() <= 1)
        return; // Base case: array of size 1 or less is already sorted
    // else if (arr.size < 20) inserionSort(arr); return;

    int mid = arr.size() / 2; // Divide the array into two halves

    vector<int> left(arr.begin(), arr.begin() + mid); // Create left subarray
    vector<int> right(arr.begin() + mid, arr.end());  // Create right subarray
    cout << left.size() << " " << right.size() << endl;

    // Recursively sort the left and right subarrays
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted left and right subarrays back into the original array
    mergePalma(arr, left, right);
}

int main()
{
    // Ejemplo de uso
    vector<int> arr = {4, 1, 9, 3, 8};
    vector<int> U = {1, 3, 5, 7};
    vector<int> V = {2, 4, 6, 8};
    vector<int> T(U.size() + V.size());

    mergeSort(arr);

    cout << "Array mezclado: ";
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}