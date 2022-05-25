#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class FileOutput
{
private:
	ifstream fin;
public:
	FileOutput()
	{
		fin.open("field.txt");
	}
	void FullOutput()
	{
		char c;
		while (fin >> c)
		{
			cout << c;
		}
	}
};

