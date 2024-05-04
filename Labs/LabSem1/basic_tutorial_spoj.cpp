#include <iostream>

using namespace std;

int main()
{
    /**
     * Rewrite small numbers from input to output.
     * Stop processing input after reading the number 42.
     */
    int num = 0;
    const int TERMINATION_SIGNAL = 42; // STOP_INPUT

    while (num != TERMINATION_SIGNAL)
    {
        cin >> num;

        if (num == TERMINATION_SIGNAL)
            return 0;

        cout << num << endl;
    }

    return 0;
}
