// Observer test

#include "stdafx.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
#define DATA void *
class Subject;

class Observer
{
public:
	Observer() {}
	virtual void Update(Subject * sb) = 0;
	virtual ~Observer() {};
};

class Subject
{
	list<Observer *> mObservers;

	DATA mData;
public:
	void SetState(DATA dt)
	{
		mData = dt;
	}

	DATA GetState()
	{
		return mData;
	}

	void attach(Observer * pObserver)
	{
		mObservers.push_back(pObserver);
	}

	void detach(Observer * pObserver)
	{
		mObservers.erase(find_if(mObservers.begin(), mObservers.end(), [pObserver](Observer * pIObserver) {
			return pIObserver == pObserver;
		}));
	}

	void NotifyAll()
	{
		for_each(mObservers.begin(), mObservers.end(), [&](Observer * pObserver) {
			pObserver->Update(this);
		});
	}
};

///<ConcertSubject>Source</ConcertSubject>
class Source :public Subject
{

};


///<ConcertObserver>Listener</ConcertObserver>
class Listener : public Observer
{
public:
	Listener() {}
	~Listener() {}
	void Update(Subject * sb)
	{
		cout <<(char *)sb->GetState()<<endl;
	}
};

int main()
{
	Source sb;
	Listener o1, o2;
	sb.SetState("иоиоио...");
	sb.attach(&o1);
	sb.attach(&o2);
	sb.NotifyAll();
	sb.SetState("єЩєЩєЩ...");
	sb.detach(&o1);
	sb.NotifyAll();
    return 0;
}

