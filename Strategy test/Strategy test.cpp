// Strategy test

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

///<Interface>MyStrategy</Interface>
class Strategy
{
public:
	Strategy() {}
	virtual ~Strategy() {}
	virtual void MyStrategy() = 0;
};

class FlyAction : public Strategy
{
	void MyStrategy() override
	{
		cout <<"I can Fly!"<<endl;
	}
};

class SwimAction : public Strategy
{
	void MyStrategy() override
	{
		cout << "I can Swim!" << endl;
	}
};

class Duck
{
public:
	void DuckAction(Strategy * Action) 
	{
		Action->MyStrategy();
	};
};

int main()
{
	Duck dk;
	//fly duck!
	dk.DuckAction(new FlyAction());
	//swim...
	dk.DuckAction(new SwimAction());
    return 0;
}

