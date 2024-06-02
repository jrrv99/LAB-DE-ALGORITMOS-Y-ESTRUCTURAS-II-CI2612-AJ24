#include <iostream>
#include <vector>

using namespace std;

#define value first
#define position second

typedef long long ll;
typedef pair<ll, int> plli;

void merge(vector<plli> &arr, vector<plli> &left, vector<plli> &right)
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

void mergeSort(vector<plli> &arr)
{
    if (arr.size() <= 1)
        return; // Base case: array of size 1 or less is already sorted
    // else if (arr.size < 20) inserionSort(arr); return;

    int mid = arr.size() / 2; // Divide the array into two halves

    vector<plli> left(arr.begin(), arr.begin() + mid); // Create left subarray
    vector<plli> right(arr.begin() + mid, arr.end());  // Create right subarray

    // Recursively sort the left and right subarrays
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted left and right subarrays back into the original array
    merge(arr, left, right);
}

int main()
{
    vector<plli> v;
    vector<int> answer;
    int t, n;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        v.resize(n);
        answer.resize(n);

        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &v[j].value);
            v[j].position = j;
        }

        mergeSort(v);

        ll score = 0;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                score += v[i].value;
                k++;
            }

            while (k < n && score >= v[k].value)
            {
                score += v[k].value;
                k++;
            }

            answer[v[i].position] = k - 1;
        }

        for (int j = 0; j < n; j++)
        {
            printf("%d ", answer[j]);
        }
        cout << endl;
    }

    return 0;
}