#include <iostream>
using namespace std;

void bubble(int a[], int n)
{
    int i, j, t, flag = 0;
    for (i = n - 1; i >= 0; i--)
    {
        flag = 0;
        for (j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void selection(int A[], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}

void insertion(int A[], int n)
{
    int i, j, v;
    for (i = 1; i < n; i++)
    {
        v = A[i];
        j = i;
        while (A[j - 1] > v && j >= 1)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = v;
    }
}

void shell(int A[], int n)
{
    int i, j, temp, gap;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void mergesort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h, t;

    while (i < j)
    {
        do
        {
            i++;
        } while (A[i] <= pivot);

        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    };
    swap(&A[l], &A[j]);

    return j;
}

void quicksort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quicksort(A, l, j);
        quicksort(A, j + 1, h);
    }
}

int findmax(int A[], int n)
{
    int max = -12365987;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void count(int A[], int n)
{
    int i, j, max, *C;
    max = findmax(A, n);

    C = new int[max + 1];

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i] = j;
            i++;
            C[j]--;
        }
        else
            j++;
    }
}

void Bucket(int A[], int n)
{
    int i, j, k, max, *C;
    max = findmax(A, n);
    C = new int[max + 1];

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }

    i = 0;
    j = 0;
    while (j < max + 1)
    {
        k = C[j];
        while (k > 0)
        {
            A[i] = j;
            i++;
            k--;
        }
        j++;
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    int n = 10;
    // int A[n] = {212, 15, 116, 187, 95, 105, 12, 145, 165, 213}; 
    // bubble(A, n);
    // selection(A, n);
    // insertion(A, n);
    // shell(A, n);
    // mergesort(A, 0, n - 1);
    // quicksort(A, 0, n);

    int A[n] = {4, 3, 6, 7, 5, 3, 4, 7, 5, 3};
    // count(A, n);
    // Bucket(A, n);
    display(A, n);
    return 0;
}