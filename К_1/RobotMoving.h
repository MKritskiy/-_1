#pragma once
#include "Header.h"
using namespace std;

class RobotMoving : public Base
{
protected:
    ofstream fout;
    int col = 0;
    int row = 0;
public:
    RobotMoving(Base* parent, string name = "RobotMoving");

    void Move(int x, int y);
    ~RobotMoving();

};