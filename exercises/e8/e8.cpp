#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct vertex
{

    string course;
    int edges;
    bool printed;
};

void printedges(bool (&matri)[18][18], vertex vertex[18])
{

    for (int rows = 0; rows < 18; rows++)
    {
        for (int cols = 0; cols < 18; cols++)
        {

            if (matri[rows][cols] == true)
            {
                cout << vertex[rows].course << "->" << vertex[cols].course << endl;
            }
        }
    }
}

string top[18];

void topsort(bool (&matri)[18][18], vertex (&verte)[18], int i, int arrin)
{

    if (verte[i].edges == 0 && verte[i].printed == false)
    {

        top[arrin] = verte[i].course;
        verte[i].printed = true;
        arrin = arrin + 1;
        for (int cols = 0; cols < 18; cols++)
        {

            if (matri[i][cols] == true)
            {
                verte[cols].edges = verte[cols].edges - 1;
            }
        }
        for (int rows = 0; rows < 18; rows++)
        {
            for (int cols = 0; cols < 18; cols++)
            {

                if (matri[rows][cols] == true && verte[cols].printed == false)
                {
                    topsort(matri, verte, cols, arrin);
                }
            }
        }
    }
    else
    {
        for (int rows = 0; rows < 18; rows++)
        {

            if (matri[rows][i] == true)
            {
                topsort(matri, verte, rows, arrin);
            }
        }
    }
}
void numEdges(bool (&matri)[18][18], vertex (&edgesset)[18])
{

    for (int cols = 0; cols < 18; cols++)
    {
        int num = 0;
        for (int rows = 0; rows < 18; rows++)
        {
            if (matri[rows][cols] == true)
            {

                num++;
            }
        }
        edgesset[cols].edges = num;
    }
}

int main()
{

    cout << "Graph filename: ";

    string file;

    cin >> file;

    cout << endl;
    ifstream myfile(file);

    int size;

    myfile >> size;

    vertex ch[18];

    string c;

    cout << "Vertices: " << endl;
    for (int i = 0; i < size; i++)
    {

        myfile >> c;
        cout << "[" << i << ":" << c << "], ";
        ch[i].course = c;
    }

    cout << endl;
    for (int k = 0; k < size; k++)
    {
        ch[k].printed = false;
    }
    bool matrix[18][18];
    for (int rows = 0; rows < size; rows++)
    {
        for (int cols = 0; cols < size; cols++)
        {

            matrix[rows][cols] = false;
        }
    }

    int edges;

    myfile >> edges;

    for (int j = 0; j < edges; j++)
    {

        int x;
        int y;
        myfile >> x;
        myfile >> y;
        matrix[x][y] = true;
    }

    cout << "Edges:" << endl;

    printedges(matrix, ch);

    cout << endl;
    numEdges(matrix, ch);

    topsort(matrix, ch, 0, 0);

    cout << "Topological sort: " << endl;
    for (int i = 0; i < 18; i++)
    {

        cout << top[i] << " ";
    }
}
