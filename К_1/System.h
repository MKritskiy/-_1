#ifndef _SYSTEM_H
#define _SYSTEM_H
#include <string>
#include <vector>
#include <iostream>
#include "Header.h"
using namespace std;
#define SIGNAL_D( signal_f ) ( signal ) ( & signal_f )
#define HANDLER_D( hendler_f ) ( handler ) ( & hendler_f )
class System : public Base
{
public:
	System(Base* parent, string name = "", int number = 1); //���������

	void BuildTree(); //��������
	void Comands(); //��������
	int ExecApp(); //��������

	void Signal(string& text); //���������
	void Handler(string text); //���������
};

#endif