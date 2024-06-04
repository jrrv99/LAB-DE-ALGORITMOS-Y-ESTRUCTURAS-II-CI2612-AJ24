#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// typedef vector<vector<uint64_t>> Matrix64;
typedef vector<vector<uint64_t>> Matrix64;
typedef vector<uint64_t> Vector64;

bool isPowerOfTwo(uint64_t n)
{
    return pow(2, log2(n)) == n;
}

int nextPowerOfTwo(int n)
{
    return pow(2, int(ceil(log2(n))));
}

Matrix64 resizeMatrix(const Matrix64 &A, int newSize)
{
    int oldSize = A.size();
    Matrix64 newMatrix(newSize, vector<uint64_t>(newSize, 0));
    for (int i = 0; i < oldSize; ++i)
        copy(A[i].begin(), A[i].end(), newMatrix[i].begin());

    return newMatrix;
}

void split(const Matrix64 &A, Matrix64 &A11, Matrix64 &A12, Matrix64 &A21, Matrix64 &A22)
{
    int n = A.size() / 2;
    for (int i = 0; i < n; ++i)
    {
        copy(A[i].begin(), A[i].begin() + n, A11[i].begin());
        copy(A[i].begin() + n, A[i].end(), A12[i].begin());
        copy(A[i + n].begin(), A[i + n].begin() + n, A21[i].begin());
        copy(A[i + n].begin() + n, A[i + n].end(), A22[i].begin());
    }
}

Matrix64 add(const Matrix64 &A, const Matrix64 &B, int sign = 1)
{
    int n = A.size();
    Matrix64 C(n, vector<uint64_t>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + sign * B[i][j];

    return C;
}

void join(const Matrix64 &A11, const Matrix64 &A12, const Matrix64 &A21, const Matrix64 &A22, Matrix64 &A)
{
    int n = A11.size();
    for (int i = 0; i < n; ++i)
    {
        copy(A11[i].begin(), A11[i].end(), A[i].begin());
        copy(A12[i].begin(), A12[i].end(), A[i].begin() + n);
        copy(A21[i].begin(), A21[i].end(), A[i + n].begin());
        copy(A22[i].begin(), A22[i].end(), A[i + n].begin() + n);
    }
}

Matrix64 strassen(const Matrix64 &A, const Matrix64 &B)
{
    int n = A.size();

    if (n == 1)
    {
        Matrix64 C = {{A[0][0] * B[0][0]}};
        return C; // return C ← A × B
    }

    int newSize = n / 2;

    // Define the matrices where the divisions of the original matrix will be stored.
    Matrix64 A11(newSize, vector<uint64_t>(newSize));
    Matrix64 A12(newSize, vector<uint64_t>(newSize));
    Matrix64 A21(newSize, vector<uint64_t>(newSize));
    Matrix64 A22(newSize, vector<uint64_t>(newSize));
    Matrix64 B11(newSize, vector<uint64_t>(newSize));
    Matrix64 B12(newSize, vector<uint64_t>(newSize));
    Matrix64 B21(newSize, vector<uint64_t>(newSize));
    Matrix64 B22(newSize, vector<uint64_t>(newSize));

    // Compute A11, A12, A21, A22, B11, B12, B21 y B22;
    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    Matrix64 P1 = strassen(add(A11, A22), add(B11, B22));
    Matrix64 P2 = strassen(add(A21, A22), B11);
    Matrix64 P3 = strassen(A11, add(B12, B22, -1));
    Matrix64 P4 = strassen(A22, add(B21, B11, -1));
    Matrix64 P5 = strassen(add(A11, A12), B22);
    Matrix64 P6 = strassen(add(A21, A11, -1), add(B11, B12));
    Matrix64 P7 = strassen(add(A12, A22, -1), add(B21, B22));

    Matrix64 C11 = add(add(add(P1, P4), P5, -1), P7);
    Matrix64 C12 = add(P3, P5);
    Matrix64 C21 = add(P2, P4);
    Matrix64 C22 = add(add(add(P1, P3), P2, -1), P6);

    Matrix64 C(n, vector<uint64_t>(n));
    join(C11, C12, C21, C22, C);
    return C;
}

int main()
{
    uint32_t n, i, j, p1, d1, r1, m1, p2, d2, r2, m2;
    Matrix64 A, B;
    Matrix64 C;
    Vector64 V;

    // here you need to read n, p1, d1, r1, m1, p2, d2, r2, m2 from input.
    scanf("%d %d %d %d %d %d %d %d %d", &n, &p1, &d1, &r1, &m1, &p2, &d2, &r2, &m2);

    A.resize(n, vector<uint64_t>(n));
    B.resize(n, vector<uint64_t>(n));
    V.resize(n, 0);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }

    // Calculate C = A * B using Strassen's algorithm
    if (!isPowerOfTwo(n))
    {
        int newSize = nextPowerOfTwo(n);
        C = strassen(resizeMatrix(A, newSize), resizeMatrix(B, newSize));
        // Resize C back to the original size
        Matrix64 tempC(n, vector<uint64_t>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tempC[i][j] = C[i][j];
        C = tempC;
    }
    else
    {
        C = strassen(A, B);
    }

    // Compute vector V
    for (i = 0; i < n; ++i)
    {
        V[i] = 0;
        for (j = 0; j < n; ++j)
            V[i] ^= C[i][j];
        printf("%ld ", V[i]);
    }

    return 0;
}