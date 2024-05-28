#include <iostream>
using namespace std;

#define size 10

class Queue
{
    int *Q;
    int front, Rear;

public:
    Queue()
    {
        Q = new int[size];
        front = Rear = -1;
    }
    void enqueue(int x);
    int dequeue();
    void display();
    void DEqueue1(int x);
    void DEqueue2();
    void DEqueue3();
    void Display();
    void DEqueue4(int x);
    void DEqueue5();
    void DEqueue6(int x);
    void Display2();
};

void Queue::enqueue(int x)
{
    if ((Rear + 1) % size == front)
        cout << "queue is full" << endl;
    else
    {
        Rear = (Rear + 1) % size;
        Q[Rear] = x;
    }
}

int Queue::dequeue()
{
    int x;
    if (front == Rear)
        return 0;
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i;
    for (i = front + 1; i != (Rear + 1) % size; i = (i + 1) % size)
        cout << Q[i] << " ";
}

void Queue::DEqueue1(int x) // Input Restricted Dequeue
{
    if ((front + 1) % size == Rear)
        cout << "Queue is full" << endl;
    else
    {
        front = (front + 1) % size;
        Q[front] = x;
    }
}

void Queue::DEqueue2()
{
    int x;
    if (front == Rear)
        cout << "Queue is Empty" << endl;
    else
    {
        x = Q[front];
        front = (front - 1) % size;
    }
}

void Queue::DEqueue3()
{
    int x;
    if (Rear == front)
        cout << "Queue elements are deleted" << endl;

    else
    {
        Rear = (Rear + 1) % size;
        x = Q[Rear];
    }
}

void Queue::Display()
{
    int i;
    for (i = Rear + 1; i != (front + 1) % size; i = (i + 1) % size)
        cout << Q[i] << " ";
}

void Queue::DEqueue4(int x) // Output restricted Dequeue
{
    if ((Rear + 1) % size == front)
        cout << "Queue is full" << endl;
    else
    {
        Rear = (Rear + 1) % size;
        Q[Rear] = x;
    }
}

void Queue::DEqueue5()
{
    int x;
    if (front == Rear)
        cout << "queue is empty" << endl;
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
}

void Queue::DEqueue6(int x)
{
    Q[front] = x;
}

void Queue::Display2()
{
    int i;
    for (i = front + 1; i <= Rear; i = (i + 1) % size)
        cout << Q[i] << " ";
}

int main()
{
    Queue q;
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // q.dequeue();
    // q.dequeue();
    // q.display();
    /*-------------------------------------------------------------------------------------------------*/
    // q.DEqueue1(10);
    // q.DEqueue1(20);
    // q.DEqueue1(30);
    // q.DEqueue1(40);
    // q.DEqueue1(50);
    // q.DEqueue2();
    // q.DEqueue3();
    // q.Display();
    /*-------------------------------------------------------------------------------------------------*/
    q.DEqueue4(20);
    q.DEqueue4(50);
    q.DEqueue4(60);
    q.DEqueue4(70);
    q.DEqueue5();
    q.DEqueue6(100);
    q.Display2();
    return 0;
}