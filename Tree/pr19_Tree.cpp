#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    Node *rchild, *lchild;
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
    Node *p, *t;
    int x;
    cout << "enter root data" << endl;
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(root);
    while (front != NULL)
    {
        p = dequeue();
        cout << "enter left child of " << p->data << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        cout << "enter right child of " << p->data << endl;
        cin >> x;
        if (x != 0)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

void pre(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        pre(p->lchild);
        pre(p->rchild);
    }
}

void InOrder(Node *p)
{
    if (p != NULL)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void post(Node *p)
{
    if (p != NULL)
    {
        post(p->lchild);
        post(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    create();
    pre(root);
    cout << "\n";
    InOrder(root);
    cout << "\n";
    post(root);
    return 0;
}