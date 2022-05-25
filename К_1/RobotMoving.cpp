#include "RobotMoving.h"

RobotMoving::RobotMoving(Base* parent, string name) : Base(parent, name)
{
    fout.open("field.txt", ios_base::in);
}

void RobotMoving::Move(int x, int y)
{
    if (col + x > 9 || row + y > 9)
    {
        cout << "Coordinate is wrong ( " << x << ", " << y << " )";
        return;
    }
    fout.seekp((col + x) + 10 * (row + y) + 2 * (row + y));
    col += x;
    row += y;
}

RobotMoving::~RobotMoving()
{
    fout.close();
}
