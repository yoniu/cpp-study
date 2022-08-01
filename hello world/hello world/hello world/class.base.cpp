#include <iostream>
using namespace std;

class Cs
{
public:
	void log(char* message)
	{
		cout << message << endl;
	}
	Cs()
	{
		log("[info] Console prepared!");
	}
};

class Console : public Cs
{
public:
	enum 
	{
		MessageInfo = 0, MessageWarn, MessageError;
	};
private:
	int MessageType;
public:
	Console(int type)
	{
		MessageType = type;
	}

};

int main()
{
	Console con(con.MessageInfo);
	
	cin.get();
}