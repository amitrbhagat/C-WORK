#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
} *poly = NULL;

void create()
{
    Node *t, *last = NULL;
    int i, num;
    cout << "enter number of terms"
         << "\n";
    cin >> num;
    cout << "enter the coefficient and exponent"
         << "\n";
    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->coeff << "x" << p->exp << " + ";
        p = p->next;
    }
}

long Eval(Node *p, int x)
{
    long eval = 0;
    while (p != NULL)
    {
        eval += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return eval;
}

int main()
{
    create();
    cout << Eval(poly, 2);
    // Display(poly);
    return 0;
}