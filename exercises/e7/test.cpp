#include "PriorityQueue.h"
using namespace std;

int main()
{

    pqueue<string, 100> pq;

    cout << "Enter 0 to quit: ";

    int quit;

    cin >> quit;

    cout << endl;

    while (quit != 0)
    {

        int enOrDe;

        cout << "type 1 insert and 2 for delete: ";

        cin >> enOrDe;

        if (enOrDe == 1)
        {
            cout << "What you want to add: ";

            string adding;

            cin >> adding;

            cout << endl;

            cout << "What is the priority of the thing: ";

            int priority;

            cin >> priority;

            cout << endl;

            pq.enqueue(adding, priority);
        }
        else if (enOrDe == 2)
        {
            pq.dequeue();
        }

        pq.printq();

        cout << "Enter 0 to quit: ";

        cin >> quit;

        cout << endl;
    }
}
