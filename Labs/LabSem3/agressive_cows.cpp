#include <iostream>
#include <vector>

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

void mergeSort(vector<int> &arr)
{
    if (arr.size() <= 1)
        return; // Base case: array of size 1 or less is already sorted
    // else if (arr.size < 20) inserionSort(arr); return;

    int mid = arr.size() / 2; // Divide the array into two halves

    vector<int> left(arr.begin(), arr.begin() + mid); // Create left subarray
    vector<int> right(arr.begin() + mid, arr.end());  // Create right subarray

    // Recursively sort the left and right subarrays
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted left and right subarrays back into the original array
    merge(arr, left, right);
}

int binarySearch(vector<int> &arr, int target)
{
    // set up the binary search
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found, return its index
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Target is in the right subarray
        }
        else
        {
            right = mid - 1; // Target is in the left subarray
        }
    }

    return -1; // Target not found
}

bool canPlaceCows(const vector<int> &stalls, int N, int C, int min_dist)
{
    /**
     * This function checks if it is possible to place C cows in the stalls,
     * so that the minimum distance between any pair of cows is at least
     * min_dist (middle pointer).
     */
    int numWorks = 1; // First cow placed at the first stall
    int previous = stalls[0];

    // there is one thing here that i dont get, with i++ the time is 0.04 but
    // with ++i the time is 0.05
    for (int i = 1; i < N; i++)
    {
        // check the distance between the last that works, and the current
        // stall
        if (min_dist <= stalls[i] - previous)
        {
            numWorks++;           // add another cow
            previous = stalls[i]; // set the last stall with cow

            // if all the cows have already been placed we can say that it
            // works (it was found, in terms of binary search)
            if (numWorks == C)
                return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int t_cases, N, cows, low, middle, high;
    int answer;
    vector<int> stalls;

    scanf("%d", &t_cases);

    while (t_cases--)
    {
        scanf("%d %d", &N, &cows);

        // clean up previous test data
        stalls.clear();
        stalls.resize(N);

        // read the stalls positions
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &stalls[i]);
        }

        // sort the array with merge sort
        mergeSort(stalls);

        /**
         * Set up the binary search
         */
        low = 1; // left
        // right: diff_between(last_stall, first_stall)
        high = stalls[N - 1] - stalls[0];
        answer = 0;

        while (low <= high)
        {
            middle = low + (high - low) / 2;

            if (canPlaceCows(stalls, N, cows, middle))
            {
                answer = middle;  // save the current largest minimum distance
                low = middle + 1; // raise the lowest pointer
            }
            else
            {
                high = middle - 1; // decrease the highest pointer
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
