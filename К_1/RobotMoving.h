#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class RobotMoving
{
protected:
    ofstream fout;
    int col = 0;
    int row = 0;
public:
    RobotMoving()
    {
        fout.open("field.txt", ios_base::in);
    }
    void Move(int x, int y)
    {
        if (col + x > 9 || row + y > 9)
        {
            cout << "Coordinate is wrong ( " << x << ", " << y << " )";
            return;
        }
        fout.seekp((col + x) + 10*(row + y) + 2*(row + y));
        col += x;
        row += y;
    }
};