#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
} *top = NULL;

void push(char x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "overflow" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    Node *t;
    char x = -1;

    if (top == NULL)
        cout << "Stack is Empty";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void RemoveDuplicate(string s)
{
    int i, j = 0;
    char B[20];
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    for (i = i - 1; i >= 0; i--)
    {
        if (top == NULL || top->data != s[i])
        {
            push(s[i]);
        }
        else if (top->data == s[i])
        {
            pop();
        }
    }
    while (top != NULL)
        B[j++] = pop();
    B[j] = '\0';
    cout << B;
}

int main()
{
    string s = "careermonk";
    string s1 = "mississippi";
    RemoveDuplicate(s);
    cout << "\n";
    RemoveDuplicate(s1);
    return 0;
}