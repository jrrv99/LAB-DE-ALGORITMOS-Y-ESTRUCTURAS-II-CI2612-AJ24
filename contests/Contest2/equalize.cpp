#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

/**
 * This is still inefficient
 * Time O(n^2)
 * Memory: O(n^2)
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, ai;

    // Map to store the frequency of keys where each key is calculated as ai + p
    // The set<int> stores the positions (p) in which the number appears.
    // Since a set does not allow duplicates, the size of the set gives us the frequency
    // of the key in different positions, effectively the frequency in a permutation.
    map<int, set<int>> frequency;

    cin >> t; // Read the number of test cases

    while (t--)
    {
        cin >> n; // Read the size of the array for the current test case

        int max_count = 0;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++)
        {
            cin >> ai; // Read the current element

            // Iterate through all possible positions (1 to n)
            for (int p = 1; p <= n; p++)
            {
                int key = ai + p;         // Calculate the key as the sum of the element and the position
                frequency[key].insert(p); // Insert the position into the set for this key

                // Update the maximum frequency count
                max_count = max(max_count, static_cast<int>(frequency[key].size()));
            }
        }

        // Output the maximum frequency count for this test case
        cout << max_count << "\n";

        // Clear the frequency map for the next test case
        frequency.clear();
    }

    return 0;
}
