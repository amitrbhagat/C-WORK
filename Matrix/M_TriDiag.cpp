#include <iostream>
using namespace std;

class matrix
{
    int *A;
    int n;

public:
    matrix()
    {
        A = new int[3 * n - 2];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void create();
    void display();
};

void matrix::set(int i, int j, int x)
{
    if (i - j == 0)
        A[n - 1 + i - 1] = x;
    else if (i - j == 1)
        A[i - 2] = x;
    else if (i - j == -1)
        A[2 * n - 1 + i - 1] = x;
}

int matrix::get(int i, int j)
{
    if (i - j == 0)
        return A[n - 1 + i - 1];
    else if (i - j == 1)
        return A[i - 2];
    else if (i - j == -1)
        return A[2 * n - 1 + i - 1];
    else
        return 0;
}

void matrix::create()
{
    int i, j, x;
    cout << "enter the total" << endl;
    cin >> n;
    cout << "enter the dimension" << endl;
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
            if (i - j == 0)
                cout << A[n - 1 + i - 1] << " ";
            else if (i - j == 1)
                cout << A[i - 2] << " ";
            else if (i - j == -1)
                cout << A[2 * n - 1 + i - 1] << " ";
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