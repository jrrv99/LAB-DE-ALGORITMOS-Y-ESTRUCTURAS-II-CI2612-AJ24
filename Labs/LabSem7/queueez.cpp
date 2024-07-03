#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

struct Queue
{
    Node *front;
    Node *tail;
    int count;

    // Constructor
    Queue() : front(nullptr), tail(nullptr), count(0) {}

    // Destroyer
    ~Queue()
    {
        while (!is_empty())
        {
            dequeue();
        }
    }

    /**
     * Adds an element to the end of the queue
     */
    void enqueue(int value)
    {
        Node *new_node = new Node(value);

        if (is_empty())
        {
            front = tail = new_node;
        }
        else
        {
            // update the tail to the new node
            tail->next = new_node;
            tail = new_node;
        }

        count++;
    }

    /**
     * Removes the element at the front of the queue
     */
    int dequeue()
    {
        if (is_empty())
        {
            throw out_of_range("Dequeue from an empty queue");
        }

        Node *to_delete = front;
        int value = front->value;
        front = front->next;

        delete to_delete;

        count--;

        if (is_empty())
        {
            tail = nullptr;
        }

        return value;
    }

    /**
     * Returns the element to the front of the queue without deleting it
     */
    int peek()
    {
        if (is_empty())
        {
            throw out_of_range("Peek from an empty queue");
        }

        return front->value;
    }

    /**
     * Check if the queue is empty
     */
    bool is_empty()
    {
        return front == nullptr;
    }

    /**
     * Returns the number of elements in the queue
     */
    int size()
    {
        return count;
    }
};

enum querys
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    PEEK = 3
};

int main(int argc, char const *argv[])
{
    Queue q;
    int t = 0, query, value;

    // Fast input/output
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> query;

        if (query == ENQUEUE)
        {
            cin >> value;
            q.enqueue(value);
            continue; // go to next query
        }

        if (query == DEQUEUE)
        {
            if (q.is_empty())
            {
                continue; // do nothinga and go to next query
            }

            q.dequeue();
            continue; // go to next query
        }

        // query == PEEK

        if (q.is_empty())
        {
            printf("Empty!\n");
            continue; // go to next query
        }

        printf("%d\n", q.peek());
    }

    return 0;
}
