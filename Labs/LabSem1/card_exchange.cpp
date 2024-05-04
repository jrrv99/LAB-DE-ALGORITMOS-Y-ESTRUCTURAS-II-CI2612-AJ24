#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_of_tests, n, k, test, j, answer;
    vector<int> cards;
    /**
     * count_map:
     * Keeps track of each card in the initial hand
     * A kind of key:value structure
     * {card: count}
     */
    vector<int> count_map;

    cin >> num_of_tests;

    for (test = 0; test < num_of_tests; test++)
    {
        cin >> n >> k;
        answer = n;

        // clean up previous test
        count_map.clear();
        count_map.resize(101);
        cards.clear();
        cards.resize(n);

        for (j = 0; j < n; j++)
        {
            cin >> cards[j];
            count_map[cards[j]]++;

            /**
             * If there are at least k cards with the same number, then
             * there are always k - 1 cards left at the end of the `exchange algorithm`.
             * else always left the initial amount of cards `n`
             */
            if (count_map[cards[j]] >= k)
                answer = k - 1;
        }

        cout << answer << endl;
    }

    return 0;
}
