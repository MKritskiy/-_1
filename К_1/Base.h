#ifndef _BASE_H
#define _BASE_H
#include <string>
#include <vector>
#include<iostream>

using namespace std;
class Base;
typedef void (Base ::* signal) (string&);
typedef void (Base ::* handler) (string);
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
public:
	Base(Base* parent, string name = "", int number = 0); //��������

	void PrintTree(); //�� ��_3_2

	void SetConnection(signal sig, Base* to, handler hand); //���������
	void DelConnection(signal sig, Base* to, handler hand); //���������
	void Emit(signal sig, string& message); //���������

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
};
#endif
