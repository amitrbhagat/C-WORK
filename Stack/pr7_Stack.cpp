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

char stacktop()
{
    if (top != NULL)
        return top->data;
    return 0;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull()
{
    char x;
    Node *t = new Node;
    t->data = x;
    if (t == NULL)
        return 1;
    return 0;
}

int isMatch(string s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            push(s[i]);
        else
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    return 0;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else
        return 0;
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void intopost(char infix[])
{
    char postfix[20];
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[j] >= 'A' && infix[j] <= 'Z') || (infix[j] >= 'a' && infix[j] <= 'z'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && top->data != '(')
            {
                postfix[j++] = pop();
            }
            if (!isEmpty())
            {
                pop();
            }
        }
        else
        {
            if (pre(infix[i]) > pre(top->data))
            {
                push(infix[i]);
            }
            else
            {
                postfix[j++] = pop();
                push(infix[i]);
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    cout << postfix;
}

int multiMatch(char A[])
{
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            push(A[i]);
        }
        else if (A[i] == ')' && top != NULL)
        {
            if (top->data == '(')
                pop();
            else
                return 0;
        }
        else if (A[i] == '}' && top != NULL)
        {
            if (top->data == '{')
                pop();
            else
                return 0;
        }
        else if (A[i] == ']' && top != NULL)
        {
            if (top->data == '[')
                pop();
            else
                return 0;
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

void intopre(char infix[])
{
    char prefix[20], temp;
    int i = 0, j, k;
    for (j = 0; infix[j] != '\0'; j++)
    {
    }
    j--;
    while (j >= 0)
    {
        if ((infix[j] >= 'A' && infix[j] <= 'Z') || (infix[j] >= 'a' && infix[j] <= 'z'))
        {
            prefix[i++] = infix[j--];
        }

        else if (infix[j] == ')')
        {
            push(infix[j--]);
        }

        else if (infix[j] == '(')
        {
            while (!isEmpty() && top->data != ')')
            {
                prefix[i++] = pop();
            }
            if (!isEmpty())
            {
                pop();
            }
            j--;
        }
        else
        {
            if (pre(infix[j]) >= pre(top->data))
                push(infix[j--]);
            else
                prefix[i++] = pop();
        }
    }
    while (top != NULL)
        prefix[i++] = pop();
    prefix[i] = '\0';
    i--;
    k = 0;
    while (k < i)
    {
        temp = prefix[k];
        prefix[k] = prefix[i];
        prefix[i] = temp;
        k++;
        i--;
    }
    cout << prefix;
}

int pelindrome()
{
    Node *p;
    char A[] = "madam was i saw madam";
    char s[0];
    int i, j = 0;

    for (i = 0; A[i] != '\0'; i++)
    {
        push(A[i]);
    }
    while (top != NULL)
    {
        s[j++] = pop();
    }
    s[j] = '\0';

    j--;
    for (i = 0; A[i] != '\0'; i++, j--)
    {
        if (A[i] != s[j])
            return 0;
    }
    return 1;
}

int main()
{
    // char infix[] = "(a-b/c)*(a/k-l)";
    // push('#'); // It is essential for comparison , example=+A*B-C
    // intopost(infix);
    // char infix[] = "A^B*C-C+D/A/(E+F)";
    // push('#'); // It is essential for comparison , example=+A*B-C
    // intopre(infix);
    // cout << isMatch("(())");
    // char A[] = "[{()}]";
    // cout << multiMatch(A);
    // cout << pelindrome();
    // display(top);
    return 0;
}