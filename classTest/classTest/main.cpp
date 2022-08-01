#include <iostream>
using namespace std;

class Cs
{
protected:
	int x = 0, y = 0;
public:
	void log(const char* message)
	{
		cout << message << endl;
	}
	virtual void setXY(int a, int b) 
	{
		this->x = a;
		this->y = b;
	}
	Cs()
	{
		log("[INFO] Console prepared!");
	}
	~Cs()
	{
		log("[INFO] Console closed!");
	}
};

class Console : public Cs
{
public:
	enum MessageType
	{
		MessageError = 0, MessageWarn, MessageInfo
	};
private:
	MessageType m_LogType = MessageInfo;
	mutable int e = 0;
public:
	Console(MessageType type)
		: e(1)
	{
		m_LogType = type;
	}

	void setXY(int a, int b)
	{
		this->x += a;
		this->y += b;
	}

	void echoXY() const
	{
		e += x + y;
		cout << "x = " << x << "; y = " << y << ";" << "e = " << e << ";" << endl;
	}

	void mInfo()
	{
		if (m_LogType >= MessageInfo)
			this->log("[INFO] Yes!");
	}

	void mError()
	{
		if (m_LogType >= MessageError)
			log("[ERROR] Sorry!");
	}
	
	void mWarn()
	{
		if (m_LogType >= MessageWarn)
			log("[WARN] Bye!");
	}
};

int main()
{
	Console console(Console::MessageInfo);
	console.log("[NMSL] 88!");
	console.mError();
	console.echoXY();
	console.setXY(10, 20);
	console.mInfo();
	console.mWarn();
	console.echoXY();

	cin.get();
}