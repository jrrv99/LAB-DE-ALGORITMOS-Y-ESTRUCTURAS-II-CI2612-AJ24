#include <iostream>
#include <vector>
#include <queue>
#include <functional> // Para greater

using namespace std;

int sumTopFiveLargest(const vector<int> &nums)
{
    // Min-heap de tamaño 5
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums)
    {
        if (minHeap.size() < 5)
        {
            minHeap.push(num);
        }
        else if (num > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(num);
        }
    }

    int sum = 0;
    while (!minHeap.empty())
    {
        cout << minHeap.top() << endl;
        sum += minHeap.top();
        minHeap.pop();
    }

    return sum;
}

int main()
{
    vector<int> nums = {100, 20, 30, 90, 50, 60, 10, 80, 40, 20}; // Ejemplo de arreglo
    int result = sumTopFiveLargest(nums);
    cout << "La suma de los 5 valores más grandes es: " << result << endl;

    return 0;
}
