#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int priority;
} *front = NULL, *Rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if (t == NULL)
    {
        cout << "queue is full" << endl;
    }
    else
    {
        if (front == NULL)
            front = Rear = t;
        else
        {
            Rear->next = t;
            Rear = t;
        }
    }
}

int Dequeue()
{
    Node *t;
    int x = -1;
    if (front == NULL)
        cout << "empty" << endl;
    else
    {
        t = front;
        x = front->data;
        front = front->next;
        delete t;
    }
    return x;
}

void display()
{
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    // enqueue(10), enqueue(20);
    // enqueue(30), enqueue(40), enqueue(50);
    // Dequeue();
    // display();

    pEnqueue(10, 2);
    pEnqueue(20, 1);
    pdisplay();
    return 0;
}