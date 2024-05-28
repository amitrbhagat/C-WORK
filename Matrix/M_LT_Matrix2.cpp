#include <iostream>
using namespace std;

// COLUMN MAJOR LOWER TRAINGULAR MATRIX
class matrix
{
    int *A;
    int n;

public:
    matrix()
    {
        // n=5;
        A = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void create();
    void display();
};

void matrix::set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int matrix::get(int i, int j)
{
    if (i >= j)
        return A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void matrix::create()
{
    cout << "enter dimension" << endl;
    cin >> n;
    cout << "enter elements" << endl;

    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> x;
            set(i, j, x);
        }
    }
}

void matrix::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}

int main()
{

    matrix m;
    m.create();
    cout << endl;
    m.display();
    return 0;
}