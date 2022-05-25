#pragma once
#include "Header.h"
using namespace std;
class FileOutput : public Base
{
private:
	ofstream fout;
public:
	FileOutput(Base* parent, string name = "FileOutput");
	void WriteError(string text);

};

