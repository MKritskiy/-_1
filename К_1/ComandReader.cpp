#include "ComandReader.h"

ComandReader::ComandReader(Base* parent, string name, int number) : Base(parent, name, number) {}

void ComandReader::ReadComand(string &comand)
{
    getline(cin, comand);
	vector<string> splited = Split(comand);
    if (splited[0] != "MOVE" && splited[0] != "WRITE" && splited[0] != "END" && splited[0]!="SHOWTREE")
    {
		Emit(SIGNAL_D(ComandReader::ErrorSignal), 6, comand);
		return;
    }
	Emit(SIGNAL_D(ComandReader::Signal), 1, comand);
}

void ComandReader::ErrorHandler(string& text)
{
    if (GetState())
    {
        cout << text;
    }
}

void ComandReader::ErrorSignal(string& text)
{
	if (GetState())
	{
		text = "ERROR command: " + text;
	}
}

void ComandReader::Signal(string& text)
{}

void ComandReader::Handler(string& text)
{
	if (GetState())
	{
		ReadComand(text);
	}
}