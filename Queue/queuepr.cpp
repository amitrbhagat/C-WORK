#include <iostream>
using namespace std;

#define size 10

class queue
{
    int *Q;
    int front, Rear;

public:
    queue()
    {
        Q = new int[size];
        front = Rear = -1;
    }
    void Enqueue(int x);
    void display();
    int Dequeue();
    void CirEnqueue(int x);
    void Cirdisplay();
    int CirDequeue();
};

void queue::Enqueue(int x)
{
    if (Rear == size)
        cout << "queue is full" << endl;
    else
    {
        Rear++;
        Q[Rear] = x;
    }
}

int queue::Dequeue()
{
    int x = -1;
    if (front == Rear)
        cout << "Queue is Empty" << endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void queue::display()
{
    int i;
    for (i = front + 1; i <= Rear; i++)
    {
        cout << Q[i] << " ";
    }
}

void queue::CirEnqueue(int x)
{
    if (Rear + 1 % size == front)
        cout << "Queue if full" << endl;
    else
    {
        Rear = Rear + 1 % size;
        Q[Rear] = x;
    }
}

int queue::CirDequeue()
{
    int x = -1;
    if (front == Rear)
        cout << "empty" << endl;
    else
    {
        front = front + 1 % size;
        x = Q[front];
    }
    return x;
}

void queue::Cirdisplay()
{
    int i;
    for (i = front + 1; i <= Rear; i = i + 1 % size)
        cout << Q[i] << " ";
}

int main()
{
    queue q;
    // q.Enqueue(10), q.Enqueue(20), q.Enqueue(30), q.Enqueue(40), q.Enqueue(50), q.Enqueue(60);
    //  q.display();
    // cout << q.Dequeue() << " " << q.Dequeue();

    q.CirEnqueue(10), q.CirEnqueue(20), q.CirEnqueue(30), q.CirEnqueue(40), q.CirEnqueue(50), q.CirEnqueue(60);
    q.Cirdisplay();
    cout << q.CirDequeue() << " ";
    return 0;
}