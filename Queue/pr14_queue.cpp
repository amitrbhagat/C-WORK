#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *front = NULL, *Rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = t;
    if (Rear == NULL)
    {
        front = Rear = t;
    }
    else
    {
        Rear->next = t;
        Rear = t;
        Rear->next = front;
    }
}

int dequeue()
{
    Node *p;
    int x;
    if (front == NULL)
        return 0;
    else
    {
        p = front;
        front = front->next;
        Rear->next = front;
        x = p->data;
        delete p;
    }
    return x;
}

int peek()
{
    if (front == NULL)
        return 0;
    return front->data;
}

void display(Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != front);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    cout << peek() << "\n";
    dequeue();
    display(front);
    cout << "\n"
         << dequeue();
    return 0;
}