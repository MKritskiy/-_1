#include "FileOutput.h"

FileOutput::FileOutput(Base* parent, string name, int number) : Base (parent, name, number)
{}

void FileOutput::ErrorSignal(string& text) {}
void FileOutput::ErrorHandler(string& text)
{
	if (GetState())
	{
		ofstream fout;
		fout.open("field.txt", ios_base::in | ios_base::ate);
		fout << '\n'<<text;
		fout.close();
	}
}
void FileOutput::Signal(string& text) {}
void FileOutput::Handler(string& text) {}


