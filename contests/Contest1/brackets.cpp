#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string const PAIR_BRACKETS = "<>,{},[],()";
    string const OPENING_BRACKETS = "<{[(";
    vector<char> opening_stack;
    string rbs, pair;
    int answer = 0, i = 0;

    cin >> rbs;

    for (i = 0; i < rbs.length(); i++)
    {
        // This comparison is slower
        // We combine consecutive characters
        pair = rbs[i];
        pair += rbs[i + 1];

        if (PAIR_BRACKETS.find(pair) != -1)
        {
            // If the pair matches, we skip it
            i += 1;
            continue;
        }

        if (OPENING_BRACKETS.find(rbs[i]) != -1)
        {
            // Add opening brackets
            opening_stack.push_back(rbs[i]);
            continue;
        }

        if (opening_stack.size() == 0)
        {
            // More closing brackets than opening brackets
            printf("Impossible\n");
            return 0;
        }

        // Combine the last opening bracket and the current closing brackets
        pair = opening_stack.back();
        pair += rbs[i];

        // If they don't match, add 1 to the answer
        answer += (PAIR_BRACKETS.find(pair) == -1) ? 1 : 0;

        // Remove the opening bracket that has been analyzed
        opening_stack.pop_back();
    }

    if ((opening_stack.size() != 0))
    {
        // More opening brackets than closing brackets
        printf("Impossible");
        return 0;
    }

    printf("%d\n", answer);

    return 0;
}
