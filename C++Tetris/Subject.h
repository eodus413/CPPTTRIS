#pragma once
#include "Observer.h"
#include "LinkedList.h"
class Subject
{
public:
	void Attach(Observer* observer) { observer_list.Add(observer); }
	void Detach(Observer* observer) { observer_list.DeleteAll(); }
	Subject();
	~Subject();

protected:
	void notify()
	{
		for (int i = 0; i < observer_list.GetSize(); i++)
			observer_list.GetData(i)->Update();
	}
public:
	virtual void Change() = 0;

private:
	LinkedList<Observer*> observer_list;
};

