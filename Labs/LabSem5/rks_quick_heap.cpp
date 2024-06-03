#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct CacheItem
{
    int key;
    int index;
};

struct KeyItem
{
    int key;
    int frequency;
    int index;

    bool operator>(const KeyItem &other) const
    {
        return (this->frequency > other.frequency) || (this->frequency == other.frequency && this->index < other.index);
    }
};

void swap(KeyItem &a, KeyItem &b)
{
    KeyItem temp = a;
    a = b;
    b = temp;
}

int partition(vector<KeyItem> &arr, int low, int high)
{
    KeyItem pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;           // Index of the last element smaller than the pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]); // Swap the current element with the element at i
        }
    }

    swap(arr[i + 1], arr[high]); // Swap the pivot with the element at i + 1

    return i + 1; // Return the new pivot index
}

void quickSort(vector<KeyItem> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Sort the left subarray
        quickSort(arr, pivotIndex + 1, high); // Sort the right subarray
    }
}

void heapify(vector<KeyItem> &arr, int n, int i)
{
    int largest = i;       // Inicializa el nodo más grande como raíz
    int left = 2 * i + 1;  // Hijo izquierdo
    int right = 2 * i + 2; // Hijo derecho

    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && arr[largest] > arr[left])
        largest = left;

    // Si el hijo derecho es más grande que el nodo más grande hasta ahora
    if (right < n && arr[largest] > arr[right])
        largest = right;

    // Si el nodo más grande no es la raíz
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursivamente heapify el subárbol afectado
        heapify(arr, n, largest);
    }
}

void heapSort(vector<KeyItem> &arr)
{
    int n = arr.size();

    // Construir el heap (reorganizar el array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--)
    {
        // Mover la raíz actual al final
        swap(arr[0], arr[i]);

        // Llamar a heapify en el heap reducido
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    /**
     * Since we only need the frequency of occurrence and the first occurrence
     * rate to sort the message, we only store the keys next to their
     * frequency in the array sorted by their first occurrence. This means
     * that we store the key the first time, and the following ones we
     * increase the frequency. This way we sort fewer elements.
     *
     * Here's the thing, with bubble sort it does not matter the order in the
     * array, because it only exchanges if it is greater or smaller (depending
     * on the case) but with heapsort and quicksort, there is always an 
     * exchange even if it is not greater or smaller, so in these cases it is
     * necessary to use the first index of appearance in the message.
     */
    int UNDEFINED = -1;
    int num_of_items, C, i, j, key;
    vector<KeyItem> message_frequency;              // (key, frequency)
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
            message_frequency[cached_item.index].frequency++; // increase the frequency

            continue; // read the next key on the message
        }

        bool found = false;

        // search the key in the array
        for (j = 0; j < message_frequency.size(); j++)
        {
            if (message_frequency[j].key == key)
            {
                message_frequency[j].frequency++; // increase the frequency
                cached_item = {key, j};           // and cached it
                found = true;                     // set as found
                break;
            }
        }

        // key does not exist
        if (!found)
        {
            KeyItem newNumber = {key, 1, j};
            message_frequency.push_back(newNumber); // add it at last
            cached_item = {key, j};                 // cached it // j because j++ set the last new index
        }
    }

    // sort it by frequency
    // quickSort(message_frequency, 0, message_frequency.size() - 1); // 0.06s
    heapSort(message_frequency); // 0.05s

    for (int index = 0; index < message_frequency.size(); index++)
    {
        // printf("(%d, %d) ", message_frequency[index].first, message_frequency[index].second);
        for (j = 0; j < message_frequency[index].frequency; j++)
        {
            // prints the key times the frequency
            printf("%d ", message_frequency[index].key);
        }
    }
}