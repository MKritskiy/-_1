#pragma once
#include "Header.h"
using namespace std;

class ComandReader : public Base
{
public:
    ComandReader(Base* parent, string name = "ComandReader", int number = obj_comand_reader);
    void ReadComand(string& comand);

    void ErrorSignal(string& text); 
    void ErrorHandler(string& text);
    void Signal(string& text);
    void Handler(string& text);
};
