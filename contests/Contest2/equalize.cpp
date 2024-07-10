#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int max_reps(vector<int> a);

int main(int argc, char const *argv[])
{
    // Fast i/o (i think it's still n!)
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

        sort(a.begin(), a.end());

        mfoe = 0;

        do
        {
            mfoe = max(mfoe, max_reps(a));
        } while (next_permutation(a.begin(), a.end()));

        cout << mfoe << "\n";
    }

    return 0;
}

int max_reps(vector<int> a)
{
    int result = -1, current;
    unordered_map<int, int> frequency;

    for (int i = 0; i < a.size(); i++)
    {
        current = ++frequency[a[i] + i + 1];

        result = max(result, current);
    }

    return result;
}