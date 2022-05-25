#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput(Base* parent, string name) : Base(parent, name)
{
	fin.open("field.txt");
}

void ConsoleOutput::FullOutput()
{
	char c;
	while (fin >> c)
	{
		cout << c;
	}
}

ConsoleOutput::~ConsoleOutput()
{
	fin.close();
}
