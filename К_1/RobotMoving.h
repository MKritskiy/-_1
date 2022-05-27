#pragma once
#include "Header.h"
using namespace std;

class RobotMoving : public Base
{
protected:
    int col = 0;
    int row = 0;
public:
    RobotMoving(Base* parent, string name = "RobotMoving", int number = obj_robot_moving);
    void Move(int x, int y);

    void ErrorSignal(string& text);
    void ErrorHandler(string& text);
    void Signal(string& text);
    void Handler(string& text);;

};