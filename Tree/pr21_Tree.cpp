#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;

void create(int key)
{
    Node *p, *t = root, *r = NULL;

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        while (t != NULL)
        {
            r = t;
            if (key < t->data)
                t = t->lchild;
            else if (key > t->data)
                t = t->rchild;
            else
                return;
        }
        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
}

Node *search(Node *p)
{
    int key;
    cout << "enter key you want to search" << endl;
    cin >> key;
    if (p != NULL)
    {
        while (p != NULL && p->data != key)
        {
            if (key < p->data)
                p = p->lchild;
            else
                p = p->rchild;
        }
        return p;
    }
    return 0;
}

Node *search2(int key)
{
    Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int Min(Node *p)
{
    if (root == NULL)
        return 0;
    while (p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p->data;
}

int max(Node *q)
{
    if (root == NULL)
        return 0;
    while (q->rchild != NULL)
    {
        q = q->rchild;
    }
    return q->data;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *succ(Node *p)
{
    if (p == NULL)
        return NULL;
    while (p->lchild)
    {
        p = p->lchild;
    }
    return p;
}

Node *Delete(Node *p, int key)
{
    if (p == NULL)
        return 0;
    else if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (!p->lchild && !p->rchild)
        {
            delete p;
            p = NULL;
        }
        else if (!p->lchild)
        {
            Node *temp = p;
            p = p->rchild;
            delete temp;
        }
        else if (!p->rchild)
        {
            Node *temp = p;
            p = p->lchild;
            delete temp;
        }
        else
        {
            Node *temp = succ(p->rchild); // Replace wth mnimum node in right subtree
            p->data = temp->data;
            p->rchild = Delete(p->rchild, temp->data);
        }
    }
    return p;
}

int main()
{
    create(60), create(50), create(90), create(40), create(35), create(75);
    create(70), create(80), create(35), create(95), create(94), create(97);
    Delete(root, 40);
    Inorder(root);
    // cout << "\n";
    // cout << search(root);
    //  cout << search2(90);
    // cout << Min(root) << " ";
    // cout << max(root);
    return 0;
}