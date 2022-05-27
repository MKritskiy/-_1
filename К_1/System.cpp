#include "Header.h"
using namespace std;

System::System(Base* parent, string name, int number) : Base(parent, name, number) {}

void System::BuildTree()
{
	string name1, name2;
	int n;
	this->children.push_back(this);
	CreatePrepare* createPrepare = new CreatePrepare(this);
	ComandReader* comandReader = new ComandReader(this);
	RobotMoving* robotMoving = new RobotMoving(this);
	Writer* writer = new Writer(robotMoving);
	FileOutput* fileOutput = new FileOutput(this);
	ConsoleOutput* consoleOutput = new ConsoleOutput(this);

	//Connections with System
	this->SetConnection(SIGNAL_D(System::Signal), createPrepare, HANDLER_D(CreatePrepare::Handler));
	this->SetConnection(SIGNAL_D (System::Signal), comandReader, HANDLER_D (ComandReader::Handler));
	this->SetConnection(SIGNAL_D(System::Signal), robotMoving, HANDLER_D(RobotMoving::Handler));
	this->SetConnection(SIGNAL_D(System::Signal), writer, HANDLER_D(Writer::Handler));
	this->SetConnection(SIGNAL_D(System::Signal), consoleOutput, HANDLER_D(ConsoleOutput::Handler));
	
	//Connections with comandReader
	comandReader->SetConnection(SIGNAL_D(ComandReader::Signal), this, HANDLER_D(System::Handler));

	robotMoving->SetConnection(SIGNAL_D(RobotMoving::Signal), writer, HANDLER_D(Writer::Handler));

	//Error conections with FileOutput
	comandReader->SetConnection(SIGNAL_D(ComandReader::ErrorSignal), fileOutput, HANDLER_D(FileOutput::ErrorHandler));
	robotMoving->SetConnection(SIGNAL_D(RobotMoving::ErrorSignal), fileOutput, HANDLER_D(FileOutput::ErrorHandler));
	writer->SetConnection(SIGNAL_D(Writer::ErrorSignal), fileOutput, HANDLER_D(FileOutput::ErrorHandler));

	//Error conections with ConsoleOutput
	createPrepare->SetConnection(SIGNAL_D(CreatePrepare::ErrorSignal), fileOutput, HANDLER_D(ConsoleOutput::ErrorHandler));


}

void System::ComandProcessing(string& command)
{
	static bool first = true;
	if (command == "END")
	{
		command = "END";
		return;
	}
	if (command == "SHOWTREE")
	{
		ofstream fout;
		fout.open("field.txt", ios_base::in | ios_base::ate);
		if (!first)
		{
			fout<<'\n';
		}
		//cout << "Object tree" << endl;
		//CPrintTree();
		//command = "END";
		fout << "Object tree\n";
		FPrintTree(fout);
		fout.close();
		exit(0);
	}
	vector<string> splited = Split(command);
	if (splited[0] == "MOVE")
	{
		int x = stoi(splited[1]);
		int y = stoi(splited[2]);
		Emit(SIGNAL_D(System::Signal), obj_robot_moving, command);
	}
	if (splited[0] == "WRITE")
	{
		Emit(SIGNAL_D(System::Signal), obj_writer, splited[1]);
	}
	first = false;
}

int System::ExecApp()
{
	this->SetReadyAll();
	Emit(SIGNAL_D(System::Signal), obj_create_prepare, name);
	string cmd;
	while (true)
	{
		Emit(SIGNAL_D(System::Signal), obj_comand_reader,  cmd);
		if (cmd == "END")
			break;
	}
	Emit(SIGNAL_D(System::Signal), obj_console_output, name);
	return 0;
}


void System::Signal(string& text)
{}

void System::Handler(string& text)
{
	if (GetState())
	{
		ComandProcessing(text);
	}
}