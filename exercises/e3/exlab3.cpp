#include <iostream>
#include <cmath>
#include <array>

using namespace std;

double firstFormula(double x, double y)
{

    return sin(x) * cos(x);
}

double secondFormula(double x, double y)
{

    return sin(x) + cos(y / 2) * cos(y / 2) - x / y;
}
double thirdFormula(double x, double y)
{

    double f = 0.5 * sin(x) + 0.5 * cos(y);
    return f;
}
double fourthFormula(double x, double y)
{

    return 0.5 * sin(x) + x * cos(3 * y);
}

int main()
{

    while (true)
    {
        cerr << "Select your function:\n 1. sin(x)cos(y)\n 2. sin(x)+cos^2(y/2)-x/y\n 3. 1/2 sin(x) + 1/2 cos(y)\n 4. 1/2 sin(x) + xcos(3y)\n 0. Quit\n"
             << endl;

        int whichFunction;

        int graduations;

        int mapOrValues;

        cin >> whichFunction;
        if (whichFunction == 0)
        {
            break;
        }
        cerr << "Nummber of graduations per axis: ";

        cin >> graduations;

        cerr << "(0) Bitmap or (1) Values? ";

        cin >> mapOrValues;

        double calc[(graduations * graduations) + graduations];

        double xIncrementer = 10.0 / graduations;
        double yIncrementer = 17.0 / graduations;

        int temp = 0;

        for (double y = -12; y < 5;)
        {
            for (double x = -4; x < 6;)
            {

                if (whichFunction == 1)
                {
                    calc[temp] = firstFormula(x, y);
                    temp++;
                }
                else if (whichFunction == 2)
                {
                    calc[temp] = secondFormula(x, y);
                    temp++;
                }
                else if (whichFunction == 3)
                {
                    calc[temp] = thirdFormula(x, y);
                    temp++;
                }
                else if (whichFunction == 4)
                {
                    calc[temp] = fourthFormula(x, y);
                    temp++;
                }
                x = x + xIncrementer;
            }
            y = y + yIncrementer;
        }
        if (mapOrValues == 1)
        {
            for (double v : calc)
            {
                cout << v << endl;
            }
        }
        if (mapOrValues == 0)
        {
            int j = graduations;
            int size = graduations * graduations;
            for (int i = 0; i < size; i++)
            {
                if (i == j)
                {
                    cout << endl;
                    j = j + graduations;
                }
                if (calc[i] < 0)
                    cout << "X";
                else
                {
                    cout << "O";
                }
            }
        }
        cout << endl;
    }
}
