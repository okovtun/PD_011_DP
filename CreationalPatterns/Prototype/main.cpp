#include<iostream>
#include<map>
using namespace std;

//Abstract prototype:
class BMW
{
protected:
	const unsigned int MAX_SPEED;
	const unsigned int DOORS;
public:
	BMW(const unsigned int MAX_SPEED, const unsigned int DOORS) :MAX_SPEED(MAX_SPEED), DOORS(DOORS) {}
	virtual ~BMW(){}
	void info()const
	{
		cout <<this<<":"<< typeid(*this).name() << "\t";
		cout << "Max speed:" << MAX_SPEED << ",\tdoors:" << DOORS << endl;
	}
	//virtual BMW* clone() const = 0;
};

//Concrete prototypes:
class BMW_3 :public BMW
{
public:
	BMW_3() :BMW(220, 3) {}
	~BMW_3(){}
	BMW* clone()const
	{
		return new BMW_3(*this);
	}
};
class BMW_5 :public BMW
{
public:
	BMW_5() :BMW(250, 4) {}
	~BMW_5(){}
	BMW* clone()const
	{
		return new BMW_5(*this);
	}
};
class BMW_7 :public BMW
{
public:
	BMW_7() :BMW(280, 5) {}
	~BMW_7(){}
	BMW* clone()const
	{
		return new BMW_7(*this);
	}
};

class BMWFactory
{
	static map<int, BMW*> prototype;
public:
	static BMW* create_model(int model)
	{
		return nullptr;//prototype[model]->clone();
	}
};
map<int, BMW*> BMWFactory::prototype =
{
	std::pair<int, BMW*>(3, new BMW_3),
	std::pair<int, BMW*>(5, new BMW_5),
	std::pair<int, BMW*>(7, new BMW_7),
};

void main()
{
	setlocale(LC_ALL, "Russian");
	/*BMW* bmw = BMWFactory::create_model(3);	bmw->info();
	BMW* bmw3 = BMWFactory::create_model(3);bmw3->info();
	BMW_3 bmw_3;
	bmw_3.info();*/

	(new BMW(240, 4))->info();
}