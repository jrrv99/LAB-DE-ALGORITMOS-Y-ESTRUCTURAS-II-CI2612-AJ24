#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
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

void heapSort(vector<int> &arr)
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
    vector<int> arr = {4, 1, 9, 3, 8};

    heapSort(arr);

    for (auto &&i : arr)
    {
        printf("%d ", i);
    }

    return 0;
}