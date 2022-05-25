#include "ComandReader.h"

ComandReader::ComandReader(Base* parent, string name) : Base(parent, name) {}

string ComandReader::ReadComand()
{
    cin >> comand;
    if (comand != "MOVE" && comand != "WRITE" && comand != "END")
    {
        comand = "ERROR comand: " + comand;
    }
    return comand;
}