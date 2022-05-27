#pragma once
#include "Header.h"
using namespace std;
class Writer : public Base
{
private:
	int prevX = 0;
	int prevY = 0;
	int x = 1;
	int y = 1;
public:
	Writer(Base* parent, string name = "Writer", int number = obj_writer);
	void Write(const char* sym);

	void ErrorSignal(string& text);
	void ErrorHandler(string& text);
	void Signal(string& text);
	void Handler(string& text);
};

