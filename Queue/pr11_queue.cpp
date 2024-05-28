#include <iostream>
using namespace std;

#define size 20

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
    int peek();
    void DEqueue1(int x);
    void DEqueue2();
    void DEqueue3();
    void Display();
    void DEqueue4(int x);
    void DEqueue5();
    void DEqueue6(int x);
};

void Queue::enqueue(int x)
{
    if (Rear == size - 1)
        cout << "queue is full" << endl;
    else
    {
        Rear++;
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
        front++;
        x = Q[front];
    }
    return x;
}

int Queue::peek()
{
    front++;
    return Q[front];
}

void Queue::display()
{
    int i;
    for (i = front + 1; i <= Rear; i++)
        cout << Q[i] << " ";
}

void Queue::DEqueue1(int x) // Input Restricted Dequeue
{
    int y;
    if (front == size - 1)
        cout << "Queue is full" << endl;
    else
    {
        front++;
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
        front--;
    }
}

void Queue::DEqueue3()
{
    int x;
    if (Rear == front)
    {
        cout << "Queue elements are deleted" << endl;
    }
    else
    {
        x = Q[Rear + 1];
        Rear++;
    }
}

void Queue::Display()
{
    int i;
    for (i = Rear + 1; i <= front; i++)
        cout << Q[i] << " ";
}

void Queue::DEqueue4(int x)
{
    if (Rear == size - 1)
        cout << "Queue is full" << endl;
    else
    {
        Rear++;
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
        x = Q[front + 1];
        front++;
    }
}
void Queue::DEqueue6(int x)
{
    Q[front] = x;
    front--;
}

int main()
{
    Queue q;
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // cout << q.dequeue() << "\n";
    // cout << q.peek() << "\n";
    // q.display();

    /*------------------------------------------for DEqueue------------------------------------------------*/
    /*---------------------------input restricted Dequeue--------------------------------------*/
    // q.DEqueue1(20);
    // q.DEqueue1(30);
    // q.DEque9ue1(40);
    // q.DEqueue1(50);
    // q.DEqueue1(60);
    // q.DEqueue1(70);
    // q.DEqueue2();
    // q.DEqueue3();
    // q.DEqueue3();
    // q.DEqueue3();
    // q.Display();
    /*------------------------------------------for DEqueue------------------------------------------------*/
    /*---------------------------output restricted Dequeue--------------------------------------*/
    q.DEqueue4(10), q.DEqueue4(20), q.DEqueue4(30), q.DEqueue4(40);
    q.DEqueue5();
    q.DEqueue6(100);
    q.display();
    return 0;
}