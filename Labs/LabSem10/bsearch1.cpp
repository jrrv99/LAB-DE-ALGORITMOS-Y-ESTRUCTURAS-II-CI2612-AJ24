#include <iostream>

using namespace std;

int const NOT_FOUND = -1;

enum NodeColor
{
    RED,
    BLACK
};

struct Data
{
    int value;
    int index;
};

struct Node
{
    Data data;
    NodeColor color;
    Node *left, *right, *parent;

    Node(Data val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct RedBlackTree
{
    Node *root;

    RedBlackTree() : root(nullptr) {}

    /**
     * swapColors: Swap the colors of two nodes
     * Args:
     *    a: Reference to the first color
     *    b: Reference to the second color
     */
    void swapColors(NodeColor &a, NodeColor &b)
    {
        NodeColor temp = a;
        a = b;
        b = temp;
    }

    /**
     * rotateLeft: Perform a left rotation on the node pt
     * Args:
     *    pt: Pointer to the node to be rotated
     */
    void rotateLeft(Node *&pt)
    {
        Node *pt_right = pt->right;

        // Turn pt_right's left subtree into pt's right subtree
        pt->right = pt_right->left;

        if (pt->right != nullptr)
            pt->right->parent = pt;

        // Update pt_right's parent to pt's parent
        pt_right->parent = pt->parent;

        // If pt is root, then update root to pt_right
        if (pt->parent == nullptr)
            root = pt_right;
        else if (pt == pt->parent->left)
            // If pt is left child of its parent
            pt->parent->left = pt_right;
        else
            // If pt is right child of its parent
            pt->parent->right = pt_right;

        // Update pt and pt_right
        pt_right->left = pt;
        pt->parent = pt_right;
    }

    /**
     * rotateRight: Perform a right rotation on the node pt
     * Args:
     *    pt: Pointer to the node to be rotated
     */
    void rotateRight(Node *&pt)
    {
        Node *pt_left = pt->left;

        // Turn pt_left's right subtree into pt's left subtree
        pt->left = pt_left->right;

        if (pt->left != nullptr)
            pt->left->parent = pt;

        // Update pt_left's parent to pt's parent
        pt_left->parent = pt->parent;

        // If pt is root, then update root to pt_left
        if (pt->parent == nullptr)
            root = pt_left;
        else if (pt == pt->parent->left)
            // If pt is left child of its parent
            pt->parent->left = pt_left;
        else
            // If pt is right child of its parent
            pt->parent->right = pt_left;

        // Update pt and pt_left
        pt_left->right = pt;
        pt->parent = pt_left;
    }

    /**
     * insertFixUp: Fix up the tree after insertion to maintain red-black properties
     * Args:
     *    pt: Pointer to the newly inserted node
     */
    void insertFixUp(Node *&pt)
    {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
        {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left)
            {
                Node *uncle_pt = grand_parent_pt->right;

                // Case 1: The uncle of pt is also red
                if (uncle_pt != nullptr && uncle_pt->color == RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    // Case 2: pt is right child of its parent
                    if (pt == parent_pt->right)
                    {
                        rotateLeft(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // Case 3: pt is left child of its parent
                    rotateRight(grand_parent_pt);
                    swapColors(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            else
            {
                Node *uncle_pt = grand_parent_pt->left;

                // Case 1: The uncle of pt is also red
                if ((uncle_pt != nullptr) && (uncle_pt->color == RED))
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    // Case 2: pt is left child of its parent
                    if (pt == parent_pt->left)
                    {
                        rotateRight(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // Case 3: pt is right child of its parent
                    rotateLeft(grand_parent_pt);
                    swapColors(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

    /**
     * find: Check if a value exists in the tree
     * Args:
     *    root: Pointer to the root of the tree
     *    value: The value to be searched for
     * Returns:
     *    The index if the value exists, NOT_FOUND otherwise
     */
    int find(Node *root, int value)
    {
        if (root == nullptr)
            return NOT_FOUND;

        // Return found index of value
        if (value == root->data.value)
            return root->data.index;

        if (value < root->data.value)
            return find(root->left, value);

        return find(root->right, value);
    }

    /**
     * insert: Insert a new value into the tree, avoiding duplicates
     * Args:
     *    data: The data to be inserted
     */
    void insert(Data data)
    {
        /* Insert in the tree in the usual way */

        // Avoid duplicates
        if (find(root, data.value) != NOT_FOUND)
            return;

        Node *pt = new Node(data);

        if (root == nullptr)
        {
            root = pt;
            pt->color = BLACK;
            return;
        }

        Node *parent = nullptr;
        Node *current = root;

        while (current != nullptr)
        {
            parent = current;
            if (pt->data.value < current->data.value)
                current = current->left;
            else
                current = current->right;
        }

        pt->parent = parent;

        if (pt->data.value < parent->data.value)
            parent->left = pt;
        else
            parent->right = pt;

        /* Now restore the red-black property */
        insertFixUp(pt);
    }
};

int main(int argc, char const *argv[])
{
    int N, Q, query;
    RedBlackTree T;

    // Fast input/output
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;

    // Read the values
    for (int i = 0; i < N; i++)
    {
        Data data = {0, i};

        cin >> data.value;

        T.insert(data);
    }

    // Read and do the queries
    while (Q--)
    {
        cin >> query;

        printf("%d\n", T.find(T.root, query));
    }

    return 0;
}
