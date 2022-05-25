#pragma once
#include <fstream>
#include <string>
using namespace std;
class ErrorMessages
{
private:
	ofstream fout;
public:
	ErrorMessages()
	{
		fout.open("field.txt", ios_base::in | ios_base::ate);
	}
	void WriteError(string text)
	{
		fout << endl<<text;
	}
};

