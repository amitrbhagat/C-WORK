#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    node *t = new node;
    t->data = x;
    t->next = NULL;
    if (t == NULL)
        cout << "full";
    else
    {
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    node *t;
    int x = -1;
    if (front == NULL)
        cout << "empty";
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][7], int start, int n)
{
    int i = start;
    int j;
    int visited[7] = {0};
    cout << i;
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue(); // counter
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << " " << j;
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int i = start;
    int j;

    // cout << i << " ";

    if (visited[i] == 0)
    {
        cout << i << " ";
        visited[i] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 4, 7);
    cout << endl;

    DFS(G, 4, 7);

    return 0;
}