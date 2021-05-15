#pragma once
#include "Date.h"
#include "Time_.h"

class Order
{
protected:
	Date date;
	Time_ time;
	string id;

public:
	Order();
	Order(Date date, Time_ time, string id);
	virtual ~Order();

	void setDate(Date date);
	Date getDate();

	void setTime(Time_ time);
	Time_ getTime();

	void setId(string id);
	string getId();

	virtual string type() = 0;
	virtual string toString()=0;

	virtual void save(ofstream& file) = 0;
	virtual void load(ifstream& file) = 0;
	

};

