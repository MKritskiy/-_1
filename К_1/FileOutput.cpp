#include "FileOutput.h"

FileOutput::FileOutput(Base* parent, string name) : Base (parent, name)
{
	fout.open("field.txt", ios_base::in | ios_base::ate);
}

void FileOutput::WriteError(string text)
{
	fout << endl << text;
}
