#pragma once
#include "Header.h"
using namespace std;
class ConsoleOutput : public Base
{
private:
	ifstream fin;
public:
	ConsoleOutput(Base* parent, string name = "ConsoleOutput");
	void FullOutput();
	~ConsoleOutput();
};

