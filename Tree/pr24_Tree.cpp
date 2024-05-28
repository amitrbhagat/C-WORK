#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild, *rchild;
    int data;
    bool Ltag, Rtag;
} *root = NULL;

Node *ThreadedBtree(Node *root, int key)
{
    Node *ptr = root;
    Node *par = NULL;

    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            cout << "Duplicate Node" << endl;
            return root;
        }
        par = ptr;
        if (key < ptr->data)
        {
            if (ptr->Ltag == false)
            {
                ptr = ptr->lchild;
            }
            else
                break;
        }
        else
        {
            if (ptr->Rtag == false)
            {
                ptr = ptr->rchild;
            }
            else
                break;
        }
    }

    Node *temp = new Node;
    temp->data = key;
    temp->Ltag = temp->Rtag = true;

    if (par == NULL)
    {
        root = temp;
        temp->lchild = temp->rchild = NULL;
    }
    else if (key < ptr->data)
    {
        temp->lchild = par->lchild;
        temp->rchild = par;
        par->Ltag = false;
        par->lchild = temp;
    }
    else
    {
        temp->lchild = par;
        temp->rchild = par->rchild;
        par->Rtag = false;
        par->rchild = temp;
    }
    return root;
}

Node *inordersuccessor(Node *p)
{
    if (p->Rtag == true)
        return p->rchild;

    p = p->rchild;
    while (p->Ltag == false)
        p = p->lchild;

    return p;
}

void inorder(Node *p)
{
    if (root == NULL)
        cout << "root is empty " << endl;

    while (p->Ltag == false)
    {
        p = p->lchild;
    }
    while (p != NULL)
    {
        cout << p->data << " ";
        p = inordersuccessor(p);
    }
}

int main()
{
    root = ThreadedBtree(root, 5);
    ThreadedBtree(root, 3);
    ThreadedBtree(root, 4);
    ThreadedBtree(root, 2);
    inorder(root);
    return 0;
}