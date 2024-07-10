#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// O(n! * n)

// Function to return the maximum number of times any element repeats
// in the array after adding a permutation to its elements.
int max_reps_backtracking(vector<int> &a, int index, unordered_map<int, int> &frequency, int &max_count);

int main()
{
    // Fast input/output configuration
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, mfoe; // t: number of test cases, n: size of the array, mfoe: max frequency of elements
    vector<int> a;  // Vector to store the array

    cin >> t; // Read the number of test cases

    while (t--)
    {
        cin >> n; // Read the size of the array

        a.resize(n); // Resize the vector to size n

        // Read the elements of the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        mfoe = 0;                          // Initialize the max frequency of elements to 0
        unordered_map<int, int> frequency; // Map to count the frequency of each element

        // Call the backtracking function to calculate the max frequency of elements
        max_reps_backtracking(a, 0, frequency, mfoe);

        cout << mfoe << "\n"; // Print the result for the current test case
    }

    return 0;
}

// Function to calculate the maximum number of times any element repeats
// after adding a permutation to the elements of the array using backtracking
int max_reps_backtracking(vector<int> &a, int index, unordered_map<int, int> &frequency, int &max_count)
{
    if (index == a.size())
    {
        return max_count;
    }

    for (int i = index; i < a.size(); ++i)
    {
        swap(a[index], a[i]);                       // Swap to create a new permutation
        int key = a[index] + (index + 1);           // Calculate the new element
        frequency[key]++;                           // Increment the counter for the element
        max_count = max(max_count, frequency[key]); // Update the max frequency of elements

        // Recurse with the next index
        max_reps_backtracking(a, index + 1, frequency, max_count);

        frequency[key]--;     // Decrement the counter to backtrack
        swap(a[index], a[i]); // Swap back to restore the array
    }

    return max_count; // Return the result
}
