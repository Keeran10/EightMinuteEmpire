#pragma once

class Observer {

protected:
	Observer();

public:
	~Observer();
	virtual void Update() = 0;
};