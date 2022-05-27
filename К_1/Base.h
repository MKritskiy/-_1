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
	string name; //�� ��_3_2
	Base* parent; //�� ��_3_2
	int state = 1; //�� ��_3_1
	int number; //���������
	Base* current = this; //�� ��_3_2
	struct connect //���������
	{
		signal sig;
		Base* to;
		handler hand;
	};
	vector<Base*> children; //�� ��_3_2
	vector<connect> connections; //���������

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
	Base(Base* parent, string name = "", int number = obj_base); //��������

	void CPrintTree(); //�� ��_3_2
	void FPrintTree(ofstream& fout);

	void SetConnection(signal sig, Base* to, handler hand); //���������
	void DelConnection(signal sig, Base* to, handler hand); //���������
	void Emit(signal sig, int num, string& message); //���������

	void SetState(int newState); //�� ��_3_1
	int GetState(); //�� ��_3_1
	void SetReadyAll(); //���������

	void SetNumber(int newNumber); //���������
	int GetNumber(); //���������

	void SetCurrent(Base* newCurrent); //�� ��_3_2
	Base* GetCurrent(); //�� ��_3_2

	void SetName(string newName); //�� ��_3_2
	string GetName(); //�� ��_3_2

	void SetParent(Base* newParent); //�� ��_3_2
	Base* GetParent(); //�� ��_3_2

	Base* GetObjectByName(string name);//�� ��_3_2
	Base* GetObjectByPath(string path);//�� ��_3_2
	string GetPath(Base* elem); //���������

	vector<string> Split(string str);
};
#endif
