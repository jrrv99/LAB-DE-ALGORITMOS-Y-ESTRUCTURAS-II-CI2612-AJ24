#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /**
     * The sum of the values (a[i] - a[i-1]) for all integers i from 2 to n is a
     * Telescopic Series, so the maximum beauty of the matrix a always reduces
     * to (a[n] - a[1]). So the way to get the maximum beauty is to put
     * the minimum value at the beginning of the matrix and the maximum value
     * of the matrix at the end.
     * (a[n] - a[1])[n = n - 1] = (a[n - 1] - a[0]) (Index starts from 0)
     */

    int num_of_tests, test, num_of_items, i, min, max, item;

    cin >> num_of_tests;

    for (test = 0; test < num_of_tests; test++)
    {
        cin >> num_of_items;

        for (i = 0; i < num_of_items; i++)
        {
            cin >> item;

            if (i == 0)
            {
                // min = max = a[0]
                min = item;
                max = item;
                continue;
            }

            // update min and max
            if (item > max)
                max = item;
            if (item < min)
                min = item;
        }

        // print the beauty = (a[n - 1] - a[0]) = (max - min)
        cout << max - min << endl;
    }

    return 0;
}
