#include <iostream>
using namespace std;
class Node
{
public:
    Node *rchild;
    Node *lchild;
    int data;
    // char data; // It is for string = Expression Tree
    Node *next;
} *front = NULL, *Rear = NULL, *root = NULL, *top = NULL, *root1 = NULL, *root2 = NULL;

void push(Node *x)
{
    Node *t;
    t = x;
    if (t == NULL)
        cout << "overflow" << endl;
    else
    {
        t->next = top;
        top = t;
    }
}

Node *pop()
{
    Node *x;
    if (top == NULL)
        return 0;
    else
    {
        x = top;
        top = top->next;
    }
    return x;
}

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
    if (x != 0)
    {
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        enqueue(root);
    }
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

void create1()
{
    Node *p, *t;
    int x;
    cout << "enter root1 data" << endl;
    cin >> x;
    if (x != 0)
    {
        root1 = new Node;
        root1->data = x;
        root1->lchild = root1->rchild = NULL;
        enqueue(root1);
    }
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
    while (p || top != NULL)
    {
        if (p)
        {
            cout << p->data << " ";
            push(p);
            p = p->lchild;
        }
        else
        {
            p = pop();
            p = p->rchild;
        }
    }
}

void InOrder(Node *p)
{
    while (p || top != NULL)
    {
        if (p)
        {
            push(p);
            p = p->lchild;
        }
        else
        {
            p = pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void levelOrder(Node *p)
{
    cout << p->data << " ";
    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->lchild != NULL)
        {
            cout << p->lchild->data << " ";
            enqueue(p->lchild);
        }
        if (p->rchild != NULL)
        {
            cout << p->rchild->data << " ";
            enqueue(p->rchild);
        }
    }
}

int Height(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int count(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    else
        x = count(p->lchild);
    y = count(p->rchild);
    return x + y + 1;
}

int count2(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return count(p->lchild) + count(p->rchild) + 1;
}

void merge()
{
    if (root == NULL)
    {
        root2 = root1;
    }
    else if (root1 == NULL)
    {
        root2 = root;
    }
    else if (root->lchild == NULL)
    {
        root->lchild = root1;
        root2 = root;
    }
    else if (root->rchild == NULL)
    {
        root->rchild = root1;
        root2 = root;
    }
    else if (root1->lchild == NULL)
    {
        root1->lchild = root;
        root2 = root1;
    }
    else if (root1->rchild == NULL)
    {
        root1->rchild = root;
        root2 = root1;
    }
    else
    {
        cout << "no merging possible" << endl;
    }
}

Node *Expression()
{
    Node *t, *x1, *x2;
    string s;
    cout << "enter the string" << endl;
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            t = new Node;
            t->data = s[i];
            t->lchild = t->rchild = NULL;
            push(t);
        }
        else
        {
            x1 = pop();
            x2 = pop();
            t = new Node;
            t->data = s[i];
            t->lchild = x2;
            t->rchild = x1;
            push(t);
        }
    }
    return pop();
}

int LeafNode(Node *p)
{
    int count = 0;
    enqueue(p);
    while (front != NULL)
    {
        p = dequeue();
        if (p->lchild != NULL)
        {
            enqueue(p->lchild);
        }
        if (p->rchild != NULL)
        {
            enqueue(p->rchild);
        }
        else if (p->lchild == NULL && p->rchild == NULL)
        {
            count++;
        }
    }
    return count;
}

void reverse(Node *p)
{
    enqueue(p);
    while (front)
    {
        p = dequeue();
        if (p->rchild)
            enqueue(p->rchild);
        if (p->lchild)
            enqueue(p->lchild);
        push(p);
    }
    Node *x;
    while (top)
    {
        x = pop();
        cout << x->data << " ";
    }
}

void presucc(Node *p)
{
    if (p->lchild)
    {
        push(p);
        p = p->lchild;
    }
    else
    {
        while (p->rchild == NULL)
        {
            p = pop();
        }
        p = p->rchild;
    }
    cout << p->data << endl;
}

void insucc(Node *p)
{
    if (p->rchild == NULL)
    {
        p = pop();
    }
    else
    {
        p = p->rchild;
        while (p->lchild != NULL)
        {
            push(p);
            p = p->lchild;
        }
    }
    cout << p->data << endl;
}

int main()
{
    create();
    //  pre(root);
    //  cout << "\n";
    //  create1();
    //  pre(root1);
    //  InOrder(root);
    //  cout << "\n";
    //  levelOrder(root);
    //  cout << "\n";
    /*--------------------------------------For Merge------------------------------------------------*/
    // create();
    // cout << "\n";
    // create1();
    // merge();
    // pre(root2);
    // cout << "\n";
    /*--------------------------------------String-------------------------------------------------s--*/
    // cout << Expression();
    //  pre(root);
    //  cout << "\n";
    //  InOrder(root);
    //  cout << "\n";
    //  levelOrder(root);
    //  create();
    //  cout << Height(root);
    //  cout << count(root);
    //  cout << count2(root);
    //  cout << LeafNode(root);
    //  reverse(root);
    // presucc(root);
    insucc(root);
    return 0;
}