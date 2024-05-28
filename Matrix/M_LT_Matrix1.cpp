#include <iostream>
using namespace std;

// ROW MAJOR LOWER TRAINGULAR MATRIX
class matrix
{
    int *A;
    int n;

public:
    matrix()
    {
        //n = 5;
        int A[n * (n + 1) / 2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void create();
    void display();
};

void matrix::set(int i, int j, int x)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = x;
}

int matrix::get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void matrix::create()
{
    int i, j, x;
    cout << "enter dimension" << endl;
    cin >> n;
    cout << "enter all elements" << endl;

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
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
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