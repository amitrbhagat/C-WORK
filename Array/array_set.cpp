#include <iostream>
using namespace std;

void Union(int A[], int B[], int n)
{
    int i, j, k = 0;
    int C[20];
    for (i = 0; i < n; i++)
    {
        C[k] = A[i];
        k++;
    }
    for (j = 0; j < n; j++)
    {
        int found = 0;
        for (i = 0; i < n; i++)
        {
            if (B[j] == A[i])
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            C[k++] = B[j];
        }
    }
    for (int i = 0; i < k; i++)
        cout << C[i] << " ";
}

int search(int A[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] == key)
            return 1;
    }
    return 0;
}

void intersection(int A[], int B[], int n)
{
    int i, j, k = 0;
    int C[20];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i] == B[j] && !search(C, n, A[i]))
            {
                C[k++] = A[i];
            }
        }
    }
    for (i = 0; i < k; i++)
        cout << C[i] << " ";
}

void difference(int A[], int B[], int n)
{
    int i, j, k = 0;
    int C[20];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i] == B[j] && !search(C, n, A[i]))
            {
                C[k++] = A[i];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (A[i] == C[j])
            {
                A[i] = -1;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (A[i] != -1)
            cout << A[i] << " ";
    }
}

int equality(int A[], int B[], int m, int n)
{
    int i, j, k, flag = 0;
    int l1 = 0, l2 = 0;
    for (i = 0, j = 0; i < m, j < n; i++, j++)
    {
        if (i < m)
            l1++;
        if (j < n)
            l2++;
    }
    if (l1 == l2)
    {
        flag = 1;
    }
    if (flag == 1)
    {
        for (i = 0; i < m; i++)
        {
            flag = 0;
            for (j = 0; j < n; j++)
            {
                if (A[i] == B[j])
                {
                    flag = 2;
                }
            }
            if (flag == 0)
                break;
        }
    }
    if (flag == 0)
        return -1;
    else
        return 1;
}

int findmax(int A[], int n)
{
    int max = INT_MIN, i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void Hash_union(int A[], int B[], int n)
{
    int i, j, max;
    int max1 = findmax(A, n);
    int max2 = findmax(B, n);

    if (max1 > max2)
        max = max1;
    else
        max = max2;

    int H[max + 1] = {0};
    for (i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        H[B[i]]++;
    }
    for (i = 1; i < max + 1; i++)
    {
        if (H[i] >= 1)
            cout << i << " ";
    }
}

void Hash_InterSection(int A[], int B[], int n)
{
    int i, j, max;
    int max1 = findmax(A, n);
    int max2 = findmax(B, n);

    if (max1 > max2)
        max = max1;
    else
        max = max2;

    int H[max + 1] = {0};
    for (i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        H[B[i]]++;
    }
    for (i = 1; i < max + 1; i++)
    {
        if (H[i] > 1)
            cout << i << " ";
    }
}

void Hash_Difference(int A[], int B[], int n)
{
    int i, j, max;
    int max1 = findmax(A, n);
    int max2 = findmax(B, n);

    if (max1 > max2)
        max = max1;
    else
        max = max2;

    int H[max + 1] = {0};
    for (i = 0; i < n; i++)
    {
        H[A[i]] = max;
    }
    for (i = 0; i < n; i++)
    {
        H[B[i]]++;
    }
    for (i = 1; i < max + 1; i++)
    {
        if (H[i] == max)
            cout << i << " ";
    }
}

int Hash_equality(int A[], int B[], int m, int n)
{
    int i, j, max;
    int max1 = findmax(A, n);
    int max2 = findmax(B, n);

    if (max1 > max2)
        max = max1;
    else
        max = max2;

    int H1[max + 1] = {0};
    int H2[max + 1] = {0};
    for (i = 0; i < n; i++)
    {
        H1[A[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        H2[B[i]]++;
    }
    for (i = 1, j = 1; i < max + 1, j < max + 1; i++, j++)
    {
        if (H1[i] != H2[j])
            return 0;
    }
    return 1;
}

int main()
{
    // int n = 5;
    //  int A[n] = {2, 9, 21, 28, 35};
    //  int B[n] = {2, 3, 9, 18, 28};
    //  Union(A, B, n);
    //  intersection(A, B, n);
    //  difference(A, B, n);

    /*--------------------------------------------------------------------------------------------*/
    int n = 5, m = 5;
    int A[m] = {2, 9, 21, 28, 18};
    int B[n] = {2, 21, 9, 18, 28};
    // cout << equality(A, B, m, n);

    /*-------------------------------------------------------------------------------------------*/
    // Hash_union(A, B, n);
    // Hash_InterSection(A, B, n);
    // Hash_Difference(A, B, n);
    cout << Hash_equality(A, B, m, n);

    return 0;
}