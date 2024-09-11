#include <iostream>
#include <string>

using namespace std;

struct node
{
    string item;
    int priority;
    node *next;
};

void enqueue(node *&n)
{

    string payload;

    int priority;

    cout << "What you want to enter: ";
    cin >> payload;
    cout << endl;
    cout << "What is the priority you want of the thing: ";
    cin >> priority;
    cout << endl;

    node *p = n;

    if (n == NULL)
    {

        n = new node;

        n->item = payload;
        n->priority = priority;
    }
    else
    {
        node *in = new node;
        while (p->priority <= priority && p->next != NULL)
        {
            p = p->next;
        }
        if (p->priority <= priority && p->next == NULL)
        {
            in->item = payload;
            in->priority = priority;
            in->next = NULL;
            p->next = in;
        }
        else
        {
            in->item = p->item;
            in->priority = p->priority;
            in->next = p->next;
            p->item = payload;
            p->priority = priority;
            p->next = in;
        }
    }
}

void dequeue(node *&n)
{
    n = n->next;
}

int main()
{

    node *head = NULL;

    int quit;

    int enorde;
    cout << "Type 0 to quit and 1 to continue: ";
    cin >> quit;
    cout << endl;

    while (quit == 1)
    {

        if (quit == 0)
            break;

        cout << "Enter 1 for insert and 0 delete: ";
        cin >> enorde;
        cout << endl;

        if (enorde == 1)
            enqueue(head);
        else
        {
            dequeue(head);
        }
        node *q = head;

        while (q != NULL)
        {
            cout << q->item << endl;
            q = q->next;
        }
        cout << "Type 0 to quit and 1 to continue: ";
        cin >> quit;
        cout << endl;

        delete q;
    }
}
