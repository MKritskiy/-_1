#pragma once
#include "Header.h"
using namespace std;

class CreatePrepare : public Base
{
private:
    string fpath = "field.txt";
    ifstream fin;
    ofstream fout;
public:
    CreatePrepare(Base* parent, string name = "CreatePrepare");
    void CreateingAndPreparing();
    ~CreatePrepare();
};
