#include <iostream>
#include <vector>
#include <algorithm>

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));

using namespace std;

int findMaxLengthSubarray(vector<int> &arr, int n);

/**
 * This problem is odd because the trick relies on the fact that (a[i] - a[i-1])
 * in a sub-segment of the array `a` is a Telescopic Series that ends up in
 * (sub_a[n] - sub_a[1]) (Some kind of sasha array).
 *
 * We want to match the elements of the array to after adding the permutation.
 * This implies that there can be no duplicate elements in the resulting array
 * before adding the permutation.
 *
 * Then the solution lies in identify a sub-segment that satisfies the
 * condition of a maximum difference of n - 1 between its elements. This
 * sub-segment represents the set of elements that can be transformed into
 * equal values by adding a valid permutation, achieving the desired result of
 * equalizing the elements of the matrix.
 *
 * The subsegment of `a` and a subsegment of some optimal permutation give us
 * the maximum number of elements equal to the same number after the operation
 * of adding the ai + pi.
 */
int main()
{
    fastread();

    int t,
        n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Sort the array
        sort(a.begin(), a.end());

        cout << findMaxLengthSubarray(a, n) << "\n";
    }

    return 0;
}

/**
 * Finds the sub-segment of maximum length in which the difference between its
 * maximum and minimum values plus 1 (last and first element because the array
 * is sorted) does not exceed `n`. (I have moved the -1 to the left of the
 * equation)
 */
int findMaxLengthSubarray(vector<int> &arr, int n)
{
    if (n == 1)
    {
        return 1;
    }

    // Remove duplicates
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < arr.size(); ++right)
    {
        // Move the left pointer to maintain the condition
        while (arr[right] - arr[left] + 1 > n)
        {
            left++;
        }

        // Update the maximum length of the subarray
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}