#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &a, int index, unordered_map<int, int> &frequency, int &max_count, int &global_max);

int max_reps(vector<int> &a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, mfoe;
    vector<int> a;

    cin >> t;

    while (t--)
    {
        cin >> n;

        a.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        mfoe = max_reps(a);

        cout << mfoe << "\n";
    }

    return 0;
}

int max_reps(vector<int> &a)
{
    int n = a.size();
    unordered_map<int, int> frequency;
    int max_count = 0;
    int global_max = 0;
    backtrack(a, 0, frequency, max_count, global_max);
    return global_max;
}

/**
 * Function to return the maximum number of times any element repeats in the
 * array after adding a permutation to its elements using backtracking and
 * pruning.
 */
void backtrack(vector<int> &a, int index, unordered_map<int, int> &frequency, int &max_count, int &global_max)
{
    if (index == a.size())
    {
        global_max = max(global_max, max_count);
        return;
    }

    for (int i = index; i < a.size(); ++i)
    {
        swap(a[index], a[i]);             // Swap to create a new permutation
        int key = a[index] + (index + 1); // Calculate the new element
        frequency[key]++;                 // Increment the counter for the element

        if (frequency[key] > max_count)
        {
            max_count = frequency[key]; // Update the max frequency of elements
        }

        // Only recurse if the current maximum frequency is promising
        if (max_count + a.size() - index - 1 > global_max)
        {
            backtrack(a, index + 1, frequency, max_count, global_max);
        }

        frequency[key]--; // Decrement the counter to backtrack
        if (frequency[key] == 0)
        {
            frequency.erase(key); // Clean up the map
        }

        swap(a[index], a[i]); // Swap back to restore the array
    }
}