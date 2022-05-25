#include "Writer.h"

Writer::Writer(RobotMoving* parent, string name)
	: RobotMoving(parent, name)
{}

void Writer::Write(char sym)
{
	if (col == prevCol && row == prevRow)
	{
		cout << "ERROR";
		return;
	}
	if (sym >= 'a' && sym <= 'z' || sym >= 'A' && sym <= 'Z')
	{
		fout << sym;
		return;
	}
	cout << "ERROR";
}
