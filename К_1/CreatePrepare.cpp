#include "RobotMoving.h"
#include "CreatePrepare.h"

CreatePrepare::CreatePrepare(Base* parent, string name, int number)
    : Base(parent, name, number) {}

void CreatePrepare::CreateingAndPreparing()
{
    string fpath = "field.txt";
    ifstream fin;
    ofstream fout;
    fout.open(fpath, ios_base::in | ios_base::trunc);
    if (!fout.is_open())
    {
        Emit(SIGNAL_D(CreatePrepare::ErrorSignal), obj_console_output, fpath);
        fin.close();
        fout.close();
        exit(-1);
    }
    fin.open(fpath, ios_base::out | ios_base::trunc);

    for (int col = 0; col < 10; col++)
    {
        for (int row = 0; row < 10; row++)
        {
            fout << '8';
        }
        if (col < 9)
            fout << '\n';
    }
    fin.close();
    fout.close();
}

void CreatePrepare::ErrorHandler(const string& text)
{
    if (GetState())
    {
        cout << text;
    }
}
void CreatePrepare::ErrorSignal(string& text)
{
    if (GetState())
    {
        text = "File " + text + " not create";
    }
}

void CreatePrepare::Signal(string& text)
{}
void CreatePrepare::Handler(string& text)
{
    if (GetState())
    {
        CreateingAndPreparing();
    }
}

