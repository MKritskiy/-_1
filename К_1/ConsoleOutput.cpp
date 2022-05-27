#include "ConsoleOutput.h"

ConsoleOutput::ConsoleOutput(Base* parent, string name, int number) : Base(parent, name, number)
{}

void ConsoleOutput::FullOutput()
{
	ifstream fin;
	fin.open("field.txt");
	char c;
	while (fin >> c)
	{
		cout << c;
	}
	fin.close();
}

void ConsoleOutput::Signal(string& text)
{}

void ConsoleOutput::Handler(string& text)
{

}

void ConsoleOutput::ErrorSignal(string& text)
{
}

void ConsoleOutput::ErrorHandler(string& text)
{
	if (GetState())
	{
		cout << text;
	}
}
