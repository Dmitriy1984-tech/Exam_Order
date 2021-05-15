#include "Order.h"

Order::Order()
{
	this->date.setDay(12);
	this->date.setMonth(4);
	this->date.setYear(2021);
	this->time.setFormat("utc");
	this->time.setHour(12);
	this->time.setMinutes(12);
	this->time.setSeconds(12);
	this->id = id;
}

Order::Order(Date date, Time_ time, string id)
{
	this->date = date;
	this->time = time;
	this->id = id;
}

Order::~Order()
{
}

void Order::setDate(Date date)
{
	this->date = date;
}

Date Order::getDate()
{
	return date;
}

void Order::setTime(Time_ time)
{
	this->time = time;
}

Time_ Order::getTime()
{
	return time;
}

void Order::setId(string id)
{
	this->id = id;
}

string Order::getId()
{
	return id;
}
