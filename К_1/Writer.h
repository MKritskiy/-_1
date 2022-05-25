#pragma once
#include "Header.h"
using namespace std;
class Writer : public RobotMoving
{
private:
	int prevRow = 0;
	int prevCol = 0;
public:
	Writer(RobotMoving* parent, string name = "Writer");
	void Write(char sym);

};

