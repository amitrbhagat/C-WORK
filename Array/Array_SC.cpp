#include <iostream>
using namespace std;

int MissElement_1(int n)
{
  int sum = 0, s, result;
  int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};

  for (int i = 0; i < 10; i++)
  {
    sum = sum + A[i];
  }
  s = n * (n + 1) / 2;
  result = s - sum;
  return result;
}

void MissElement_2()
{
  int n = 7, l = 0;
  int A[] = {6, 7, 8, 9, 11, 12, 13};

  int diff = A[0] - l;
  for (int i = 0; i < n; i++)
  {
    if (A[i] - i != diff)
    {
      cout << (i + diff) << " ";
    }
  }
}

void MissElement_4()
{
  int H[21] = {0}, l = 0, n = 20, h = n - 1;
  int A[] = {5, 6, 8, 9, 11, 12, 13, 14, 15, 17, 18, 19, 20};
  for (int i = 0; i < 12; i++)
  {
    H[A[i]]++;
  }
  for (int i = A[l]; i <= h; i++)
  {
    if (H[i] == 0)
      cout << i << " ";
  }
}

void Duplicate()
{
  int LastDuplicate = 0;
  int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
  for (int i = 0; i < 11; i++)
  {
    if (A[i] == A[i + 1] && A[i] != LastDuplicate)
      cout << A[i] << " ";
    LastDuplicate = A[i];
  }
}

void Duplicate_2()
{
  int i, j, n = 10;
  int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
  for (i = 0; i < n - 1; i++)
  {
    if (A[i] == A[i + 1])
    {
      j = i + 1;
      while (A[j] == A[i])
        j++;
      cout << A[i] << " " << j - i << "\n";
      i = j - 1;
    }
  }
}

void Duplicate_3()
{
  int i, j, n = 10, H[21] = {0};
  int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
  for (i = 0; i <= n; i++)
  {
    H[A[i]]++;
  }
  for (i = 0; i < 21; i++)
  {
    if (H[i] > 1)
      cout << i << " " << H[i] << "\n";
  }
}

void Duplicate_5()
{
  int i, j, n = 10, H[21] = {0};
  int A[] = {3, 9, 15, 8, 13, 12, 8, 14, 15, 20};

  for (i = 0; i <= n; i++)
  {
    H[A[i]]++;
  }
  for (i = 0; i < 21; i++)
  {
    if (H[i] > 1)
      cout << i << " " << H[i] << "\n";
  }
}

void Pair()
{
  int i, j, n = 7;
  int A[] = {6, 2, 5, 1, 4, 5, 9};
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (A[i] + A[j] == 10)
        cout << "(" << A[i] << "," << A[j] << ")"
             << "\n";
    }
  }
}

void Pair_2()
{
  int i, j, n = 7;
  int A[] = {1, 2, 3, 5, 6, 7, 8};
  i = 0;
  j = n - 1;
  while (i < j)
  {
    if (A[i] + A[j] == 10)
    {
      cout << "(" << A[i] << "," << A[j] << ")"
           << "\n";
      i++;
      j--;
    }
    else if (A[i] + A[j] < 10)
    {
      i++;
    }
    else
      j--;
  }
}

void M_M_Element()
{
  int A[] = {5, 9, 23, 3, 14, 12, 16, 17};
  int max = A[0];
  int min = A[0];
  for (int i = 1; i < 8; i++)
  {
    if (A[i] > max)

      max = A[i];

    else if (A[i] < min)

      min = A[i];
  }
  cout << max << "\n";
  cout << min;
}

int InterpolationSearch(int A[], int n, int key)
{
  int i, j, l = 0, h = n - 1, mid;
  while (l < h)
  {
    mid = l + (((key - A[l]) * (h - l)) / (A[h] - A[l]));
    if (key == A[mid])
      return mid + 1; // return index
    else if (key < A[mid])
      h = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

int main()
{
  // int n = 10;
  // cout << MissElement_1(n);
  // MissElement_2();
  // MissElement_4();
  // Duplicate();
  // Duplicate_2();
  // Duplicate_3();
  // Duplicate_5();
  // M_M_Element();
  // Pair();
  // Pair_2();

  int n = 8;
  int A[n] = {5, 9, 23, 33, 44, 52, 66, 77};
  cout << InterpolationSearch(A, n, 33);

  return 0;
}