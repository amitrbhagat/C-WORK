#include <iostream>
using namespace std;

class Node
{
public:
    int data, priority;
    Node *next;
} *front = NULL, *Rear = NULL;

void enqueue(int x, int p)
{
    Node *t = new Node;
    t->next = NULL;
    t->data = x;
    t->priority = p;
    if (t == NULL)
        cout << "Queue is full" << endl;

    else if (front == NULL)
    {
        front = Rear = t;
    }
    else
    {
        Node *q = front;
        while (q->next != NULL && q->next->priority <= p)
        {
            q = q->next;
        }
        if (t->priority < front->priority)
        {
            t->next = front;
            front = t;
        }
        else if (q->next == NULL)
        {
            q->next = t;
            Rear = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void dequeue(int p)
{
    int x;
    Node *s = NULL, *q = front;
    while (q->priority < p)
    {
        s = q;
        q = q->next;
    }
    if (q == front)
    {
        front = front->next;
        q->next = NULL;
        x = q->data;
        delete q;
    }
    else
    {
        s->next = q->next;
        q->next = NULL;
        x = q->data;
        delete q;
    }
}

void display()
{
    Node *p = front;
    while (p <= Rear)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    enqueue(10, 1);
    enqueue(20, 1);
    // enqueue(30, 3);
    // enqueue(4000, 2);
    // enqueue(50, 4);

    dequeue(1);
    //  dequeue(1);
    display();
    // cout << "\n"
    //  << isEmpty();
    return 0;
}