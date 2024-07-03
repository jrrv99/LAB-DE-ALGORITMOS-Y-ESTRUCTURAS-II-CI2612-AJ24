#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {}
};

struct Stack
{
    Node *top;
    int count;

    // Constructor
    Stack() : count(0), top(nullptr) {}

    // Destroyer
    ~Stack()
    {
        while (!is_empty())
        {
            pop();
        }
    }

    /**
     * Adds a new node with the value value to the top of the stack.
     */
    void push(int value)
    {
        Node *new_node = new Node(value);

        if (is_empty())
        {
            top = new_node;
            return;
        }

        new_node->next = top;
        top = new_node;

        count++;
    }

    /**
     * Removes the node at the top of the stack.
     */
    int pop()
    {
        if (is_empty())
        {
            throw out_of_range("Pop from an empty stack");
        }

        Node *to_delete = top;
        int value = top->value;
        top = top->next;

        delete to_delete;

        count--;

        return value;
    }

    /**
     * Returns the value of the node at the top of the stack without removing it.
     */
    int peek()
    {
        if (is_empty())
        {
            throw out_of_range("Peek from an empty stack");
        }

        return top->value;
    }

    /**
     * Check if the stack is empty
     */
    bool is_empty()
    {
        return top == nullptr;
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
    PUSH = 1,
    POP = 2,
    PEEK = 3
};

int main(int argc, char const *argv[])
{
    Stack q;
    int t = 0, query, value;

    // Fast input/output
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> query;

        if (query == PUSH)
        {
            cin >> value;
            q.push(value);
            continue; // go to next query
        }

        if (query == POP)
        {
            if (q.is_empty())
            {
                continue; // do nothinga and go to next query
            }

            q.pop();
            continue; // go to next query
        }

        // query == POP

        if (q.is_empty())
        {
            printf("Empty!\n");
            continue; // go to next query
        }

        printf("%d\n", q.peek());
    }

    return 0;
}
