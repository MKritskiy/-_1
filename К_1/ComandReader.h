#pragma once
#include "Header.h"
using namespace std;

class ComandReader : public Base
{
private:
    string comand;
public:
    ComandReader(Base* parent, string name = "ComandReader");
    string ReadComand();
};
