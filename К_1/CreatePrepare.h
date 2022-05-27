#pragma once
#include "Header.h"
using namespace std;

class CreatePrepare : public Base
{
public:
    CreatePrepare(Base* parent, string name = "CreatePrepare", int number = obj_create_prepare);
    void CreateingAndPreparing();

    void ErrorSignal(string& text);
    void ErrorHandler(const string& text = "");
    void Signal(string& text);
    void Handler(string& text);
};
