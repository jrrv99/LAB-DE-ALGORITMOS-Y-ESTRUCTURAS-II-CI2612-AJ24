#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

bool isValid(Matrix &A, Matrix &B);

/**
 * Given the definition of B, we know that a B(i,j) is 0 if all the elements
 * of row i and column j of matrix A are 0. For this reason, we start with a
 * matrix A initialized to 1, then for each B(i,j) equal to 0, we set all the
 * elements of row i and column j to 0.
 * After constructing A, we check whether applying the described logical OR 
 * operation results in matrix B.
 */
int main(int argc, char const *argv[])
{
    int rows, columns;

    cin >> rows >> columns;

    // Start with a matrix A initialized to all 1's
    Matrix A(rows, vector<int>(columns, 1));
    Matrix B(rows, vector<int>(columns, -1));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> B[i][j];

            // For each 0 in B, set the entire row and column in A to 0.
            if (B[i][j] == 0)
            {
                for (int column = 0; column < columns; column++)
                {
                    A[i][column] = 0;
                }

                for (int row = 0; row < rows; row++)
                {
                    A[row][j] = 0;
                }
            }
        }
    }

    if (!isValid(A, B))
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // Prints A
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            // Don't print space at end of each line
            cout << A[row][column] << (column != columns - 1 ? " " : "");
        }
        cout << "\n";
    }

    return 0;
}

/**
 * Verify whether applying the logical OR operation to matrix A results in
 * matrix B
 */
bool isValid(Matrix &A, Matrix &B)
{
    int rows = B.size(), columns = B[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int orResult = 0;

            // logical OR on row
            for (int column = 0; column < columns; column++)
            {
                orResult |= A[i][column];
            }

            // logical OR on column
            for (int row = 0; row < rows; row++)
            {
                orResult |= A[row][j];
            }

            if (orResult != B[i][j])
            {
                return false;
            }
        }
    }

    return true;
}