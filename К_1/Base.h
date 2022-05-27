#ifndef _BASE_H
#define _BASE_H
#include <string>
#include <vector>
#include<iostream>

using namespace std;
class Base;
typedef void (Base ::* signal) (string&);
typedef void (Base ::* handler) (string&);
class Base
{
protected:
	string name; //Из КЛ_3_2
	Base* parent; //Из КЛ_3_2
	int state = 1; //Из КЛ_3_1
	int number; //Добавлено
	Base* current = this; //Из КЛ_3_2
	struct connect //Добавлено
	{
		signal sig;
		Base* to;
		handler hand;
	};
	vector<Base*> children; //Из КЛ_3_2
	vector<connect> connections; //Добавлено

	enum obj
	{
		obj_base = 0,
		obj_system = 1,
		obj_create_prepare = 2,
		obj_comand_reader = 3,
		obj_robot_moving = 4,
		obj_writer = 5,
		obj_file_output = 6,
		obj_console_output = 7
	};
public:
	Base(Base* parent, string name = "", int number = obj_base); //Изменено

	void CPrintTree(); //Из КЛ_3_2
	void FPrintTree(ofstream& fout);

	void SetConnection(signal sig, Base* to, handler hand); //Добавлено
	void DelConnection(signal sig, Base* to, handler hand); //Добавлено
	void Emit(signal sig, int num, string& message); //Добавлено

	void SetState(int newState); //Из КЛ_3_1
	int GetState(); //Из КЛ_3_1
	void SetReadyAll(); //Добавлено

	void SetNumber(int newNumber); //Добавлено
	int GetNumber(); //Добавлено

	void SetCurrent(Base* newCurrent); //Из КЛ_3_2
	Base* GetCurrent(); //Из КЛ_3_2

	void SetName(string newName); //Из КЛ_3_2
	string GetName(); //Из КЛ_3_2

	void SetParent(Base* newParent); //Из КЛ_3_2
	Base* GetParent(); //Из КЛ_3_2

	Base* GetObjectByName(string name);//Из КЛ_3_2
	Base* GetObjectByPath(string path);//Из КЛ_3_2
	string GetPath(Base* elem); //Добавлено

	vector<string> Split(string str);
};
#endif
