#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void bubbleSort(vector<pair<int, int>> &numbers)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < numbers.size(); ++i)
        {
            if (numbers[i - 1].second < numbers[i].second)
            {
                swap(numbers[i - 1], numbers[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

struct CacheItem
{
    int key;
    int index;
};

int main(int argc, char const *argv[])
{
    /**
     * Since we only need the frequency of occurrence and the first occurrence
     * rate to sort the message, we only store the keys next to their
     * frequency in the array sorted by their first occurrence. This means
     * that we store the key the first time, and the following ones we
     * increase the frequency. This way we sort fewer elements.
     */
    int UNDEFINED = -1;
    int num_of_items, C, i, j, key;
    vector<pair<int, int>> message_frequency;       // (key, frequency)
    CacheItem cached_item = {UNDEFINED, UNDEFINED}; // (key, index)

    cin >> num_of_items >> C;

    /**
     * Read the values and the frecuency
     */
    for (i = 0; i < num_of_items; i++)
    {
        cin >> key;

        // Avoid to do the search of the key in the array
        if (cached_item.key == key)
        {
            message_frequency[cached_item.index].second++; // increase the frequency

            continue; // read the next key on the message
        }

        bool found = false;

        // search the key in the array
        for (j = 0; j < message_frequency.size(); j++)
        {
            if (message_frequency[j].first == key)
            {
                message_frequency[j].second++; // increase the frequency
                cached_item = {key, j};        // and cached it
                found = true;                  // set as found
                break;
            }
        }

        // key does not exist
        if (!found)
        {
            pair<int, int> newNumber = {key, 1};
            message_frequency.push_back(newNumber); // add it at last
            cached_item = {key, j};                 // cached it // j because j++ set the last new index
        }
    }

    bubbleSort(message_frequency); // sort it by frequency

    for (int index = 0; index < message_frequency.size(); index++)
    {
        for (j = 0; j < message_frequency[index].second; j++)
        {
            // prints the key times the frequency
            cout << message_frequency[index].first << " ";
        }
    }
}