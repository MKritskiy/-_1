#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CreatePrepare
{
private:
    string fpath = "field.txt";
    ifstream fin;
    ofstream fout;
public:
    void CreateingAndPreparing()
    {
        fout.open(fpath, ios_base::in | ios_base::trunc);
        if (!fout.is_open())
        {
            cout << "File " << fpath << " not create";
            exit(-1);
        }
        fin.open(fpath, ios_base::out | ios_base::trunc);

        for (int col = 0; col < 10; col++)
        {
            for (int row = 0; row < 10; row++)
            {
                fout << '8';
            }
            if (col<9)
                fout << endl;
        }
    }
    ~CreatePrepare()
    {
        fin.close();
        fout.close();
    }
};
