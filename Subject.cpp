#include "Subject.h"

void Subject::Attach(Observer* o)
{
	_observers->push_back(o);
}

void Subject::Detach(Observer* o)
{
	_observers->remove(o);
}

void Subject::Notify()
{
	for (Observer* o : *_observers)
		o->Update();
}

Subject::Subject() {
	_observers = new list<Observer*>;
}

Subject::~Subject() {
	delete _observers;
}