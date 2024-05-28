#include <iostream>
using namespace std;

void Merge(int A[], int B[], int m, int n)
{
    int c[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            c[k++] = A[i++];
        else
            c[k++] = B[j++];
    }
    while (i < m)
        c[k++] = A[i++];
    while (j < n)
        c[k++] = B[j++];
    for (i = 0; i < k; i++)
        cout << c[i] << " ";
}

int main()
{
    int m = 5, n = 5;
    int A[m] = {1, 3, 5, 7, 9};
    int B[n] = {2, 4, 6, 8, 10};
    Merge(A, B, m, n);
    return 0;
}