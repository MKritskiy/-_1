#pragma once
#include "Header.h"
using namespace std;
class FileOutput : public Base
{
public:
	FileOutput(Base* parent, string name = "FileOutput", int number = obj_file_output);

	void ErrorSignal(string& text);
	void ErrorHandler(string& text);
	void Signal(string& text);
	void Handler(string& text);
};

