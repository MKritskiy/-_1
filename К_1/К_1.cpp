#include <iostream>
#include <fstream>
#include <string>
#include "ComandReader.h"
#include "CreatePrepare.h"
#include "RobotMoving.h"
#include "ErrorMessages.h"
#include "FileOutput.h"
#include "System.h"
#include "Writer.h"
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

