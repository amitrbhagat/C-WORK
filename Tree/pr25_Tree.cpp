#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data, height;
    Node *rchild;
} *root = NULL;

int Height(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int Balancedfactor(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

Node *LLR(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = Height(p);
    pl->height = Height(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

Node *RRR(Node *p)
{
    Node *pr = p->rchild;
    Node *plr = pr->lchild;

    pr->lchild = p;
    p->rchild = plr;

    p->height = Height(p);
    pr->height = Height(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node *LRR(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = Height(p);
    pl->height = Height(pl);
    plr->height = Height(plr);

    if (root == p)
        root = plr;

    return plr;
}

Node *RLR(Node *p)
{
    Node *pr = p->rchild;
    Node *plr = pr->lchild;

    p->rchild = plr->lchild;
    pr->lchild = plr->rchild;

    plr->lchild = p;
    plr->rchild = pr;

    p->height = Height(p);
    pr->height = Height(pr);
    plr->height = Height(plr);

    if (root == p)
        root = plr;

    return plr;
}

Node *Rinsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }

    p->height = Height(p);

    if (Balancedfactor(p) == 2 && Balancedfactor(p->lchild) == 1)
        return LLR(p);

    else if (Balancedfactor(p) == -2 && Balancedfactor(p->rchild) == -1)
        return RRR(p);

    else if (Balancedfactor(p) == 2 && Balancedfactor(p->lchild) == -1)
        return LRR(p);

    else if (Balancedfactor(p) == -2 && Balancedfactor(p->rchild) == 1)
        return RLR(p);
    return p;
}

void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    root = Rinsert(root, 4), Rinsert(root, 2), Rinsert(root, 7),
    Rinsert(root, 6), Rinsert(root, 8), Rinsert(root, 5);
    preorder(root);
    return 0;
}