#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int Matrix[n][n] = {0};
    int u, v;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        cin >> u >> v;
        Matrix[u][v] = 1;
        Matrix[v][u] = 1;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}