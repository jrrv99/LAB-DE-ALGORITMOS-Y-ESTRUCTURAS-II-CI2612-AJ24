#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// English lower case letters ([a..z]) in ASCII code range from [97..122].
// To normalize them to a range [0..25], (26 leters) we subtract the character
// 'a' (ASCII code 97).
const char ASCII_NORMALIZER_CHAR = 'a';

int main()
{
    // Fast input/output
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string u = "";
    stack<char> t;
    vector<int> remaining(26, 0); // Frequency count of remaining characters in 's'

    // Count occurrences of each character in 's'
    for (char c : s)
    {
        remaining[c - ASCII_NORMALIZER_CHAR]++;
    }

    // Process each character in the input string 's'
    for (char c : s)
    {
        t.push(c);
        remaining[c - ASCII_NORMALIZER_CHAR]--; // Decrease its frequency in 'remaining'

        // Move characters from t to u if possible
        while (!t.empty())
        {
            char top_t = t.top();
            bool can_move = true; // Checking Flag

            // Check if there is any smaller character left in 's'
            for (int i = 0; i < top_t - ASCII_NORMALIZER_CHAR; ++i)
            {
                if (remaining[i] > 0) // If a smaller character exists, we cannot move 'top_t'
                {
                    can_move = false;
                    break;
                }
            }

            if (can_move)
            {
                // Append 'top_t' to 'u' and continue to the next character
                u += top_t;
                t.pop();
                continue;
            }

            break; // Exit the while if 'top_t' cannot be moved
        }
    }

    // Move remaining characters in t to u
    while (!t.empty())
    {
        u += t.top();
        t.pop();
    }

    cout << u << "\n";

    return 0;
}
