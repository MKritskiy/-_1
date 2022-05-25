#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ComandReader
{
private:
    string comand;
public:
    string ReadComand()
    {
        cin >> comand;
        if (comand != "MOVE" && comand != "WRITE" && comand != "END")
        {
            comand = "ERROR comand: " + comand;
        }
        return comand;
    }
};
