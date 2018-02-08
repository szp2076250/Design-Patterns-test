// Composite Patterns

#include "stdafx.h"
#include <string>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class Interface
{
public:
	virtual void Do() = 0;
	virtual ~Interface() {}
};

class MenuItem : public Interface
{
	string mItemName;
public:
	void Do() { cout <<mItemName<<endl; }
	~MenuItem() {}
	MenuItem(string Name) :mItemName(Name) {}
};

class MenuBar : public Interface
{
	string mMenuName;
	list<Interface *> mList;
public:
	void Add(Interface & it) { mList.push_back(&it); }
	void Do() 
	{
		cout << mMenuName << endl;
		for_each(mList.begin(), mList.end(), [&](Interface * mi) {
			mi->Do(); 
		});
	}
	~MenuBar() {}
	MenuBar(string Name) :mMenuName(Name) {}
};

int main()
{
	MenuBar mb("--�˵�--");
	MenuItem mi("--��ʼ--");
	MenuItem mi2("--�ر�--");
	MenuItem mi3("--��ԭ--");
	mb.Add(mi); mb.Add(mi2); mb.Add(mi3);
	mb.Do();
    return 0;
}

