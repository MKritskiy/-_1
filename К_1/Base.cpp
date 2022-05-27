#include "Base.h"
#include <fstream>
Base::Base(Base* parent, string name, int number)
{
	SetParent(parent);
	SetName(name);
	SetNumber(number);
	if (parent)
		children.push_back(this);
}

void Base::CPrintTree()
{
	static int n = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "    ";
	}
	cout << children[0]->GetName();
	if (GetState())
	{
		cout << " is ready";
	}
	else
		cout << " is not ready";
	for (int i = 1; i < children.size(); i++)
	{
		n++;
		cout << endl;
		children[i]->CPrintTree();
		n--;
	}
}
void Base::FPrintTree(ofstream& fout)
{
	static int n = 0;
	for (int i = 0; i < n; i++)
	{
		fout << "    ";
	}
	fout << children[0]->GetName();
	if (GetState())
	{
		fout << " is ready";
	}
	else
		fout << " is not ready";
	for (int i = 1; i < children.size(); i++)
	{
		n++;
		fout << '\n';
		children[i]->FPrintTree(fout);
		n--;
	}
}
void Base::SetConnection(signal sig, Base* to, handler hand)
{
	if (this->GetState())
	{
		for (int i = 0; i < connections.size(); i++)
		{
			if (connections[i].sig == sig && connections[i].to == to && connections[i].hand == hand)
				return;
		}
		connections.push_back(connect{ sig, to, hand });
	}
}

void Base::DelConnection(signal sig, Base* to, handler hand)
{
	if (this->GetState())
	{
		for (auto it = connections.begin(); it != connections.end(); it++)
		{
			if (it->sig == sig && it->to == to && it->hand == hand)
			{
				connections.erase(it);
				return;
			}
		}
	}
}

void Base::Emit(signal sig, int num, string& message)
{
	if (this->GetState()) {
		(this->*(sig))(message);
		for (int i = 0; i < this->connections.size(); i++)
		{
			if (this->connections[i].sig == sig && this->connections[i].to->GetState() != 0 && this->connections[i].to->GetNumber() == num)
			{
				(connections[i].to->*(connections[i].hand))(message);
			}
		}
	}
}


void Base::SetState(int newState)
{
	if (GetParent() && GetParent()->GetState() || !GetParent())
		state = newState;
	else
		state = 0;
	if (!state)
	{
		for (int i = 1; i < children.size(); i++)
			children[i]->SetState(0);
	}
}

int Base::GetState()
{
	return state;
}

void Base::SetReadyAll()
{
	this->SetState(1);
	for (int i = 1; i < children.size(); i++)
	{
		children[i]->SetState(1);
		children[i]->SetReadyAll();
	}
}

void Base::SetCurrent(Base* newCurrent)
{
	current = newCurrent;
}

Base* Base::GetCurrent()
{
	return current;
}

void Base::SetNumber(int newNumber)
{
	number = newNumber;
}

int Base::GetNumber()
{
	return number;
}


void Base::SetName(string newName)
{
	name = newName;
}

string Base::GetName()
{
	return name;
}

void Base::SetParent(Base* newParent)
{
	if (newParent == nullptr)
	{
		parent = nullptr;
	}
	else
	{
		parent = newParent;
		parent->children.push_back(this);
	}
}

Base* Base::GetParent()
{
	return parent;
}

Base* Base::GetObjectByName(string name)
{
	Base* find = nullptr;
	for (int i = 0; i < this->children.size(); i++)
	{
		if (children[i]->GetName() == name)
		{
			find = children[i];
			return find;
		}
		else if (i > 0)
		{
			find = children[i]->GetObjectByName(name);
			if (find != nullptr)
				return find;
		}
	}
	return find;
}

Base* Base::GetObjectByPath(string path)
{
	Base* find = nullptr;
	if (path == "/")
		return this;
	else if (path == ".")
		return GetCurrent();
	else if (path.find("//") != string::npos)
		return GetObjectByName(path.substr(2, path.length() - 2));
	else if (path[0] == '/')
	{
		static int lastPos = 0;
		string name;
		if (path.find('/', lastPos + 1) == string::npos)
			name = path.substr(lastPos + 1, path.length() - lastPos);
		else
			name = path.substr(lastPos + 1, path.find('/', lastPos + 1) - lastPos - 1);
		for (int i = 0; i < this->children.size(); i++)
		{
			if (children[i]->GetName() == name)
			{
				if (path.find('/', lastPos + 1) != string::npos)
					find = children[i]->GetObjectByPath(path.substr(path.find('/', lastPos + 1), path.length() - 1));
				else
					find = children[i];
				return find;
			}
		}
	}
	else
	{
		path = '/' + path;
		find = GetCurrent()->GetObjectByPath(path);
	}
	return find;
}

string Base::GetPath(Base* elem)
{
	string path = "";
	static int n = 1;
	if (elem->GetParent())
	{
		n = 0;
		path = GetPath(elem->GetParent()) + '/' + elem->GetName();
		return path;
	}
	else
	{
		if (n)
		{
			return "/";
		}
		n = 1;
		return path;
	}
}

vector<string> Base::Split(string str)
{
	vector<string> splited;
	int lpos = 0;
	while (str.find(' ', lpos+1)!=string::npos)
	{
		splited.push_back(str.substr(lpos, str.find(' ', lpos+1)-lpos));
		lpos = str.find(' ', lpos+1)+1;
	}
	splited.push_back(str.substr(lpos, str.length() - lpos));
	return splited;
}
