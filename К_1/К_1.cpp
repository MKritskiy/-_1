#include "Header.h"
using namespace std;



int main()
{
    CreatePrepare file;
    file.CreateingAndPreparing();
    ComandReader cmdR;
    RobotMoving robot;
    Writer wrt;
    string cmd;
    while (true)
    {
        cmd = cmdR.ReadComand();
        if (cmd == "MOVE")
            wrt.Move(2, 2);
        if (cmd == "WRITE")
            wrt.Write('T');
        if (cmd == "END")
            break;
    }
}

