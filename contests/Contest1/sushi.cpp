#include <iostream>

using namespace std;

int const UNDEFINED = -1;

int main(int argc, char const *argv[])
{
    int n, current_type, latest_type = UNDEFINED,
                         last_count = 0, count = 0, answer = 0;

    cin >> n;

    while (n--)
    {
        scanf("%d", &current_type);

        // set the current as latest at first iteration
        if (latest_type == UNDEFINED)
            latest_type = current_type;

        if (current_type == latest_type)
        {
            count++; // count the equals
            continue;
        }

        // there is a change in the sequence
        // check if the subsegment is larger than the previous one
        answer = max(answer, 2 * min(last_count, count));

        latest_type = current_type; // update the latest type of sushi
        last_count = count;         // save the previous counter
        // reset the counter to 1 (the current type where change occurred)
        count = 1;
    }

    // we were doing the response when a type change occurred, but in the last
    // iteration we didn't take a change, so we didn't compare the last length
    // of the type read, so we need one more comparison after the loop ends
    answer = max(answer, 2 * min(last_count, count));

    printf("%d\n", answer);

    return 0;
}