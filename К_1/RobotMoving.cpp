#include "RobotMoving.h"

RobotMoving::RobotMoving(Base* parent, string name, int number) : Base(parent, name, number)
{}

void RobotMoving::Move(int x, int y)
{
    string message;
    if (x >= 10 || y >= 10 || x<=0 || y<=0)
    {
        message = to_string(x) + ", " + to_string(y);
        Emit(SIGNAL_D(RobotMoving::ErrorSignal), obj_file_output, message);
        return;
    }
    row = x;
    col = y;
    message = to_string(x) + " " + to_string(y);
    Emit(SIGNAL_D(RobotMoving::Signal), obj_writer, message);
}

void RobotMoving::ErrorSignal(string& text)
{
    if (GetState())
    {
        text = "Coordinate is wrong ( " + text + " )";
    }
}
void RobotMoving::ErrorHandler(string& text)
{
    if (GetState())
    {
        cout << text;
    }
}
void RobotMoving::Signal(string& text)
{}

void RobotMoving::Handler(string& text)
{
    if (GetState())
    {
        vector<string> splited = Split(text);
        int x = stoi(splited[1]);
        int y = stoi(splited[2]);
        Move(x, y);
    }
}

