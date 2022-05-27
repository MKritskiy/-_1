#include "Writer.h"

Writer::Writer(Base* parent, string name, int number)
	: Base(parent, name, number)
{}

void Writer::Write(const char* sym)
{
	ofstream fout;
	fout.open("field.txt", ios_base::in);
	if (prevX==x && prevY==y)
	{
		string message =  to_string(x) + ", " + to_string(y);
		Emit(SIGNAL_D(Writer::ErrorSignal), obj_file_output, message);
		return;
	}
	if (*sym >= 'a' && *sym <= 'z' || *sym >= 'A' && *sym <= 'Z')
	{
		fout.seekp((x - 1) * 10 + y - 1 + (x - 1) * 2);
		fout << *sym;
		prevX = x; prevY = y;
		return;
	}
	string message = string(sym);
	Emit(SIGNAL_D(Writer::ErrorSignal), obj_file_output, message);
	fout.close();
}

void Writer::ErrorSignal(string& text)
{
	if (GetState())
	{
		if (text.length() > 1)
			text = "Attempt to sequentially write to a cell ( " + text + " )";
		else
			text = "The letter does not belong to the Latin alphabet: " + text;
	}
}
void Writer::ErrorHandler(string& text)
{
	if (GetState())
	{
		cout << text;
	}
}
void Writer::Signal(string& text)
{}
void Writer::Handler(string& text)
{
	if (GetState())
	{
		if (text.length() > 1)
		{
			vector<string> splited = Split(text);
			prevX = x;
			prevY = y;
			x = stoi(splited[0]);
			y = stoi(splited[1]);
		}
		else
			Write(text.data());
	}
}