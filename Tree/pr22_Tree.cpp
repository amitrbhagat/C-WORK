#include <iostream>
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
    int x;
    Node *t, *p;
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

void preorder(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void levelorder(Node *p)
{
    cout << p->data << " ";
    enqueue(p);
    while (front)
    {
        p = dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            enqueue(p->rchild);
        }
    }
}

int H(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;

    x = H(p->lchild);
    y = H(p->rchild);

    if (x > y)
        return x + 1;
    return y + 1;
}

int count(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;

    x = count(p->lchild);
    y = count(p->rchild);

    return x + y + 1;
}

void Max(Node *p)
{
    int max = INT_MIN;
    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->data > max)
        {
            max = p->data;
        }
        if (p->lchild != NULL)
        {
            enqueue(p->lchild);
        }
        if (p->rchild != NULL)
        {
            enqueue(p->rchild);
        }
    }
    cout << max;
}

Node *search(Node *p)
{
    int key;
    cout << "enter the key" << endl;
    cin >> key;

    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->data == key)
        {
            return p;
        }
        if (p->lchild != NULL)
        {
            enqueue(p->lchild);
        }
        if (p->rchild != NULL)
        {
            enqueue(p->rchild);
        }
    }
    return NULL;
}

void Delete(Node *p)
{
    if (p == NULL)
        return;

    Delete(p->lchild); // We use postorder traversal for deletion of binary tree
    Delete(p->rchild);
    cout << p->data << " "; // Elements Deleted in the Order
    delete (p);
}

int Deep(Node *p)
{
    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->lchild)
            enqueue(p->lchild);
        if (p->rchild)
            enqueue(p->rchild);
    }
    return p->data;
}

int full(Node *p)
{
    int count = 0;
    enqueue(p);
    while (front)
    {
        p = dequeue();
        if (p->lchild && p->rchild)
        {
            count++;
        }
        if (p->lchild)
        {
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            enqueue(p->rchild);
        }
    }
    return count;
}

int half(Node *p)
{
    int count = 0;
    enqueue(p);
    while (front)
    {
        p = dequeue();
        if (p->lchild && !p->rchild || p->rchild && !p->lchild)
        {
            count++;
        }
        if (p->lchild)
        {
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            enqueue(p->rchild);
        }
    }
    return count;
}

int Total(Node *p)
{
    int sum = 0;
    enqueue(p);
    while (front)
    {
        p = dequeue();
        sum = sum + p->data;

        if (p->lchild)
        {
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            enqueue(p->rchild);
        }
    }
    return sum;
}

void mirror(Node *p)
{
    Node *x;
    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->lchild && p->rchild)
        {
            enqueue(p->lchild);
            enqueue(p->rchild);
            x = p->lchild;
            p->lchild = p->rchild;
            p->rchild = x;
        }
        else if (p->rchild && !p->lchild)
        {
            enqueue(p->rchild);
            p->lchild = p->rchild;
            p->rchild = NULL;
        }
        else if (p->lchild && !p->rchild)
        {
            enqueue(p->lchild);
            p->rchild = p->lchild;
            p->lchild = NULL;
        }
    }
}

int main()
{
    create();
    // preorder(root);
    // levelorder(root);
    // cout << H(root);
    // cout << count(root);
    // Max(root);
    // cout << search(root);
    // Delete(root);
    // cout << Deep(root);
    // cout << full(root);
    // cout << half(root);
    // cout << Diameter(root);
    // cout << Total(root);
    mirror(root);
    preorder(root);
    return 0;
}