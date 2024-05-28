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
    t->next = NULL;
    if (front == NULL)
    {
        front = Rear = t;
    }
    else
    {
        Rear->next = t;
        Rear = t;
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
        x = p->data;
        delete p;
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << dequeue() << " " << dequeue() << "\n";
    display();
    return 0;
}