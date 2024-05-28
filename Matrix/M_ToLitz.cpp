#include <iostream>
using namespace std;

class matrix
{
    int *A;
    int n;

public:
    matrix()
    {
        A = new int[n + n - 1];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void create();
    void display();
};

void matrix::set(int i, int j, int x)
{
    if (i <= j)
        A[j - i] = x;
    else if (i > j)
        A[n + i - j - 1] = x;
}

int matrix::get(int i, int j)
{
    if (i <= j)
        return A[j - i];
    else if (i > j) 
        return A[n + i - j - 1];
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
            if (i <= j)
                cout << A[j - i] << " ";
            else if (i > j)
                cout << A[n + i - j - 1] << " ";
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