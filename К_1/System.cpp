#include "Header.h"
using namespace std;

System::System(Base* parent, string name, int number) : Base(parent, name, number) {}

void System::BuildTree()
{
	string name1, name2;
	int n;
	cin >> name1;
	this->SetName(name1);
	this->children.push_back(this);
	CreatePrepare* child2 = new CreatePrepare(this);
	ComandReader* child3 = new ComandReader(this);
	RobotMoving* child4 = new RobotMoving(this);
	Writer* child5 = new Writer(child4);
	FileOutput* child6 = new FileOutput(this);
	ConsoleOutput* child7 = new ConsoleOutput(this);
}

void System::Comands()
{
	string command;
	string sigPath, handPath, objPath;
	string text;
	vector<signal> sigs = { SIGNAL_D(System::Signal), SIGNAL_D(Child2::Signal), SIGNAL_D(Child3::Signal), SIGNAL_D(Child4::Signal), SIGNAL_D(Child5::Signal),SIGNAL_D(Child6::Signal) };
	vector<handler> hands = { HANDLER_D(System::Handler),HANDLER_D(Child2::Handler) ,HANDLER_D(Child3::Handler) ,HANDLER_D(Child4::Handler) ,HANDLER_D(Child5::Handler) ,HANDLER_D(Child6::Handler) };
	while (true)
	{
		cin >> command;
		if (command == "END")
			break;
		if (command == "EMIT")
		{
			cin >> objPath;
			getline(cin, text, '\n');
			text.erase(0, 1);
			Base* obj = GetObjectByPath(objPath);
			if (obj != nullptr)
			{
				obj->Emit(sigs[obj->GetNumber() - 1], text);
			}
			else
				cout << "\nObject " << objPath << " not found";
		}
		if (command == "SET_CONNECT")
		{
			cin >> sigPath >> handPath;
			Base* sigObj = GetObjectByPath(sigPath);
			Base* handObj = GetObjectByPath(handPath);
			if (sigObj && handObj)
			{
				sigObj->SetConnection(sigs[sigObj->GetNumber() - 1], handObj, hands[handObj->GetNumber() - 1]);
			}
			else if (sigObj == nullptr)
				cout << "\nObject " << objPath << " not found";
			else if (handObj == nullptr)
				cout << "\nHandler object " << handPath << " not found";
		}
		if (command == "DELETE_CONNECT")
		{
			cin >> sigPath >> handPath;
			Base* sigObj = GetObjectByPath(sigPath);
			Base* handObj = GetObjectByPath(handPath);
			if (sigObj && handObj)
			{
				sigObj->DelConnection(sigs[sigObj->GetNumber() - 1], handObj, hands[handObj->GetNumber() - 1]);
			}
			else if (sigObj == nullptr)
				cout << "\nObject " << objPath << " not found";
			else if (handObj == nullptr)
				cout << "\nHandler object " << handPath << " not found";
		}
		if (command == "SET_CONDITION")
		{
			int newState;
			cin >> objPath >> newState;
			Base* obj = GetObjectByPath(objPath);
			if (obj != nullptr)
			{
				obj->SetState(newState);
			}
			else
				cout << "\nObject " << objPath << " not found";
		}
	}
}

int System::ExecApp()
{
	this->SetReadyAll();
	cout << "Object tree" << endl;
	this->PrintTree();
	this->Comands();
	return 0;
}


void System::Signal(string& text)
{
	if (GetState())
	{
		text = text + " (class: 1)";
		cout << "\nSignal from " << GetPath(this);
	}
}

void System::Handler(string text)
{
	if (GetState())
	{
		cout << "\nSignal to " << this->GetPath(this) << " Text:  " << text;
	}
}