#include <iostream>
#include <cmath>
using namespace std;

class Term
{
public:
    int coeff, expo;
};

class Poly
{
public:
    int n;
    Term *t;
};

void create(Poly *p)
{
    int i;
    p->t = new Term;
    cout << "Enter total number"
         << " ";
    cin >> p->n;
    cout << "Enter the Elements"
         << "\n";
    for (i = 0; i < p->n; i++)
        cin >> p->t[i].coeff >> p->t[i].expo;
}

int eval(Poly *p, int x)
{
    int i = 0;
    int sum = 0;
    while (i < p->n)
    {
        sum += p->t[i].coeff * pow(x, p->t[i].expo);
        i++;
    }
    return sum;
}

Poly *Add(Poly *p1, Poly *p2)
{
    int i, j, k;
    i = j = k = 0;
    Poly *sum;
    sum = new Poly;
    sum->t = new Term[p1->n + p2->n];
    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].expo > p2->t[j].coeff)
            sum->t[k++] = p1->t[i++];
        else if (p1->t[i].expo < p2->t[j].expo)
            sum->t[k++] = p2->t[j++];
        else
        {
            sum->t[k].expo = p1->t[i].expo;
            sum->t[k++].coeff = p1->t[i++].coeff - p2->t[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->t[k++] = p1->t[i];
    for (; j < p2->n; j++)
        sum->t[k++] = p2->t[j];
    sum->n = k;
    return sum;
}

void display(Poly *p)
{
    int i;
    for (i = 0; i < p->n; i++)
        cout << p->t[i].coeff << " x " << p->t[i].expo << " + "
             << " ";
}

int main()
{
    Poly p1, p2, *p3;
    create(&p1);
    // create(&p2);
    // p3 = Add(&p1, &p2);
    // display(p3);
    cout << "Answer is " << eval(&p1, 3);
    return 0;
}