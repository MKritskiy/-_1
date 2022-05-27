#pragma once
#include "Header.h"
using namespace std;
class ConsoleOutput : public Base
{
public:
	ConsoleOutput(Base* parent, string name = "ConsoleOutput", int number = obj_console_output);
	void FullOutput();

	void Signal(string& text);
	void Handler(string& text);

	void ErrorSignal(string& text);
	void ErrorHandler(string& text);

};

