#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double calculate(double z, double x, double y)
{

    return (cos(z) * (0.5 * sin(x) + (0.5 * cos(y))));
}

int main()
{

    ofstream out("file.pgm");

    out << "P2" << endl;

    int graduations;

    cin >> graduations;

    out << graduations;

    out << " " << graduations << endl;

    int max = 255;

    out << max << endl;

    double pgm[(graduations * graduations) * graduations];

    double xIncrementer = 10.0 / graduations;
    double yIncrementer = 17.0 / graduations;

    cout << xIncrementer << endl;
    cout << yIncrementer << endl;
    int temp = 0;

    for (double y = -12; y < 5; y = y + yIncrementer)
    {
        for (double x = -4; x < 6; x = x + xIncrementer)
        {

            pgm[temp] = calculate(0, x, y);
            temp++;
        }
    }
    cout << graduations * graduations << endl;
    cout << temp << endl;

    int plot = 0;

    for (int i = 0; i < graduations * graduations; i++)
    {

        int pixel = (int)((pgm[i] + 1) * 127.5);
        if (pixel < 10)
        {
            out << pixel << "   ";
        }
        else if (pixel < 100)
        {
            out << pixel << "  ";
        }
        else
        {
            out << pixel << " ";
        }
        plot++;
        if (plot == graduations)
        {
            plot = 0;
            out << endl;
        }
    }
}
