#include <iostream>
using namespace std;

//Topological Sort

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

int isEmpty()
{
    return front == NULL;
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

void topologicalsort(int G[][5], int n)
{
    int counter;
    int i, j;
    counter = 0;
    int indegree[5] = {0};

    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    for (i = 1; i < n; i++)
    {
        if (indegree[i] == 0)
            enqueue(i);
    }

    while (!isEmpty())
    {
        i = dequeue();
        counter++;

        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1)
            {
                indegree[j] = indegree[j] - 1;
                if (indegree[j] == 0)
                {
                    enqueue(j);
                }
            }
        }
    }
    if (counter != n - 1)
        cout << "It is a Directed cyclic graph";
    else
        cout << "Directed Acyclic Graph (Not a cyclic graph)";
}

int main()
{
    int G[5][5] =
        {{0, 0, 0, 0, 0},
         {0, 0, 1, 1, 0},
         {0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0},
         {0, 0, 1, 0, 0}};

    int n = 5;
    topologicalsort(G, n);

    return 0;
}