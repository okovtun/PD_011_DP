#include<iostream>
#include<string>
using namespace std;

typedef int Cable;

class EuropeanSocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;//Фаза
	virtual Cable neutral() = 0;//Ноль
	virtual Cable earth() = 0;//Земля
};

class Socket :public EuropeanSocketInterface
{
public:
	int voltage()
	{
		return 220;
	}

	Cable live()
	{
		return 1;
	}
	Cable neutral()
	{
		return -1;
	}
	Cable earth()
	{
		return 0;
	}
};

class USASocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;
	virtual Cable neutral() = 0;
};

class Adapter :public USASocketInterface
{
	EuropeanSocketInterface* socket;
public:
	void plugIn(EuropeanSocketInterface* fork)
	{
		socket = fork;
	}

	int voltage()
	{
		return 110;
	}

	Cable live()
	{
		return socket->live();
	}
	Cable neutral()
	{
		return socket->neutral();
	}
};

class Kettle
{
	USASocketInterface* power;
public:
	void plugIn(USASocketInterface* socket)
	{
		power = socket;
	}

	void boil()
	{
		if (power->voltage() > 110)
		{
			cout << "Fire in the hole" << endl;
		}
		else if (power->live() == 1 && power->neutral() == -1)
		{
			cout << "Biol" << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Socket socket;
	Kettle kettle;
	Adapter adapter;
	adapter.plugIn(&socket);
	kettle.plugIn(&adapter);
	kettle.boil();
}