#include <iostream>
using namespace std;

class matrix
{
private:
    int *A;
    int n;

public:
    matrix()
    {
        n = 4;
        A = new int[2 * n - 1];
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
        A[n - 1 + i - j] = x;
}

int matrix::get(int i, int j)
{
    if (i <= j)
        return A[j - i];
    else if (i > j)
        return A[n - 1 + i - j];
    else
        return 0;
}

void matrix::create()
{
    int i, j, x;
    cout << "enter dimension"
         << "\n";
    cin >> n;
    cout << "Enter the elements"
         << "\n";
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
    int i, j, x;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << A[j - i] << " ";
            else if (i > j)
                cout << A[n - 1 + i - j] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << "\n";
    }
}

int main()
{
    matrix m;
    m.create();
    cout << "\n";
    m.display();
    // cout << m.get(2, 2) << endl;
     cout << m.get(3, 3);
    return 0;
}