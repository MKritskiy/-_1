#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "RobotMoving.h"
using namespace std;
class Writer : public RobotMoving
{
private:
	int prevRow = 0;
	int prevCol = 0;
public:
	void Write(char sym)
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

};

