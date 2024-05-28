#include <iostream>
using namespace std;

class Array
{
private:
    int A[10];
    int size;

public:
    Array()
    {
        size = 0;
    }
    void Add(int x);
    void insert(int pos, int x);
    void display();
    void getarray();
    int Delete(int pos);
    int search(int x);
    int S_search(int x);
    int get(int pos);
    void set(int pos, int x);
    int max();
    int min();
    void swap(int &x, int &y);
    int B_search(int x);
    void Reverse();
    void Reverse_2();
    int sorted();
    int Sum();
    int Avg();
    void Sort_insert(int x);
    void L_Rote();
    void R_Rote();
    void L_shift();
    void R_shift();
    void Rearrange();
    void Duplicate();
};

void Array::Add(int x)
{
    A[size] = x;
    size++;
}

void Array::getarray()
{
    cout << "enter the size of an array" << endl;
    cin >> size;
    cout << "enter the array elements" << endl;

    for (int i = 0; i < size; i++)
        cin >> A[i];
}

void Array::insert(int pos, int x)
{
    if (pos > 0 && pos <= size)
    {
        for (int i = size; i > pos; i--)
        {
            A[i] = A[i - 1];
        }
    }
    A[pos] = x;
    size++;
}

int Array::Delete(int pos)
{
    int i, x = 0;
    x = A[pos];
    if (pos > 0 && pos <= size)
    {
        for (i = pos; i < size; i++)

            A[i] = A[i + 1];
        size--;
    }
    return x;
}

int Array::search(int x)
{
    int i;
    for (i = 0; i <= size; i++)
    {
        if (A[i] == x)
            return i;
    }
    return -1;
}

void Array::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int Array::S_search(int x)
{
    int i, temp;
    for (i = 0; i <= size; i++)
    {
        if (x == A[i])
        {
            swap(A[i], A[0]);
            return i;
        }
    }
    return -1;
}

int Array::get(int pos)
{
    if (pos >= 0 && pos <= size)
        return A[pos];
    return -1;
}

void Array::set(int pos, int x)
{
    if (pos >= 0 && pos <= size)
        A[pos] = x;
}

int Array::max()
{
    int Max = A[0];
    for (int i = 0; i < size; i++)
    {
        if (A[i] > Max)
            Max = A[i];
    }
    return Max;
}

int Array::min()
{
    int Min = A[0];
    for (int i = 0; i < size; i++)
    {
        if (A[i] < Min)
            Min = A[i];
    }
    return Min;
}

int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i <= size; i++)
    {
        sum += A[i];
    }
    return sum;
}

int Array::Avg()
{
    int sum = 0;
    for (int i = 0; i <= size; i++)
    {
        sum += A[i];
    }
    return sum / size;
}

int Array::B_search(int x)
{
    int mid;
    int l = 0;
    int h = size - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (x == A[mid])
            return mid;
        else if (x > A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

void Array::Reverse()
{
    int i, j;
    int B[size];
    for (i = size - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i <= size; i++)
        A[i] = B[i];
}

void Array::Reverse_2()
{
    int i, j;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        swap(A[i], A[j]);
    }
}

int Array::sorted()
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

void Array::Sort_insert(int x)
{
    int i;
    i = size - 1;
    while (A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    size++;
}

void Array::L_Rote()
{
    int i, x;
    x = A[0];
    for (i = 0; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[size - 1] = x;
}

void Array::R_Rote()
{
    int i, x;
    x = A[size - 1];
    for (i = size - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = x;
}

void Array::L_shift()
{
    for (int i = 0; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[size - 1] = 0;
}

void Array::R_shift()
{
    for (int i = size - 1; i > 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

void Array::Rearrange()
{
    int i, j;
    i = 0;
    j = size - 1;
    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }
}

void Array::display()
{
    int i;
    for (i = 0; i < size; i++)
        cout << A[i] << " ";
}

void Array::Duplicate()
{
    int i, j, x;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (A[i] == A[j])
                cout << A[j] << " ";
        }
    }
}

int main()
{
    Array a;
    a.getarray();
    // a.Add(4);
    // a.Add(5);
    // a.Add(7);
    // a.insert(3, 44);
    // a.Delete(6);
    // a.display();
    // cout << "\n";
    // cout << a.search(8);
    // cout << "\n";
    // cout << a.S_search(6);
    // cout << "\n";
    // a.display();
    // cout << a.get(2);
    // a.set(4, 33);
    // a.display();
    // cout<<a.max();
    // cout<<a.min();
    // cout << a.B_search(44);
    // a.Reverse();
    // a.Reverse_2();
    // a.display();
    // cout << a.sorted();
    // cout<<a.Sum();
    // cout << "\n";
    // cout<<a.Avg();
    // a.Sort_insert(6);
    // a.L_Rote();
    // a.R_Rote();
    // a.L_shift();
    // a.R_shift();
    // a.Rearrange();
    // a.Duplicate();
    // a.display();

    return 0;
}