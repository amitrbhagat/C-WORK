#include <iostream>
using namespace std;

class Node
{
public:
    Node *firstchild, *nextsibling;
    int data;
    Node *next;
} *front = NULL, *Rear = NULL,
  *root = NULL;

void enqueue(Node *x)
{
    Node *t;
    t = x;
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

Node *dequeue()
{
    Node *x;
    if (front == NULL)
        return 0;
    else
    {
        x = front;
        front = front->next;
    }
    return x;
}

void create()
{
    int x;
    Node *t, *p;
    cout << "enter root data" << endl;
    cin >> x;
    if (x != 0)
    {
        root = new Node;
        root->data = x;
        root->firstchild = root->nextsibling = NULL;
        enqueue(root);
    }

    while (front != NULL)
    {
        p = dequeue();
        cout << "enter firstchild of " << p->data << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node;
            t->data = x;
            t->firstchild = t->nextsibling = NULL;
            p->firstchild = t;
            enqueue(t);
        }
        cout << "enter nextsibling of " << p->data << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node;
            t->data = x;
            t->firstchild = t->nextsibling = NULL;
            p->nextsibling = t;
            enqueue(t);
        }
    }
}

void preorder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->firstchild);
        preorder(p->nextsibling);
    }
}

int Sum(Node *p)
{
    int sum = 0;
    if (p == 0)
        return 0;

    enqueue(p);
    while (front)
    {
        p = dequeue();
        sum = sum + p->data;

        if (p->firstchild)
            enqueue(p->firstchild);

        if (p->nextsibling)
            enqueue(p->nextsibling);
    }
    return sum;
}

int Count(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->nextsibling;
    }
    return count;
}

int main()
{
    create();
    // preorder(root);
    // cout << Sum(root);
    cout << Count(root->firstchild);
    return 0;
}