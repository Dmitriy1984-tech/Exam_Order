#include "RushOrder.h"
#include <string>
#include <fstream>

RushOrder::RushOrder():Order()
{
	this-> courier = "courier";
	this->deliveryDate = Date() + 2;

}

RushOrder::RushOrder(Date date, Time_ time, string id, string courier, Date deliveryDate)
	: Order(date, time, id)
{
	this->courier = courier;
	this->deliveryDate = deliveryDate;
}

RushOrder::~RushOrder()
{
}

void RushOrder::setCourier(string courier)
{
	this->courier = courier;
}

string RushOrder::getCourier()
{
	return courier;
}

void RushOrder::setDeliveryDate(Date deliveryDate)
{
	this->deliveryDate = deliveryDate;
}

Date RushOrder::getDeliveryDate()
{
	return deliveryDate;
}

string RushOrder::type()
{
	return "RushOrder";
}

string RushOrder::toString()
{
	return "Issued a rush order number " + id +
		+"\n Order date: " + to_string(date.getDay()) + " " + to_string(date.getMonth()) +" "+
		to_string(date.getYear()) + "\n Order time: " +
		to_string(time.getHour()) + ":" + to_string(time.getMinutes()) + ":" +
		to_string(time.getSeconds())+
		"\n Courier is "+courier+"\n Delivery date is " +
			to_string(deliveryDate.getDay())+" "+
			to_string(deliveryDate.getMonth())+" "+
			to_string(deliveryDate.getYear())+"\n\n";
}

void RushOrder::save(ofstream& file)
{
	file << type() << endl
		<< date << endl
		<< time << endl
		<< id << endl
		<< courier << endl
		<< deliveryDate << endl;
}

void RushOrder::load(ifstream& file)
{
	string dateLoad;
	getline(file, dateLoad);
	date.setDay(atoi(dateLoad.substr(0, 2).c_str()));
	date.setMonth(atoi(dateLoad.substr(3, 2).c_str()));
	date.setYear(atoi(dateLoad.substr(6).c_str()));

	string timeLoad;
	getline(file, timeLoad);
	time.setHour(atoi(timeLoad.substr(0, 2).c_str()));
	time.setMinutes(atoi(timeLoad.substr(3, 2).c_str()));
	time.setSeconds(atoi(timeLoad.substr(6).c_str()));

	getline(file, id);

	getline(file, courier);

	string delivaryDateLoad;
	getline(file, delivaryDateLoad);
	deliveryDate.setDay(atoi(delivaryDateLoad.substr(0, 2).c_str()));
	deliveryDate.setMonth(atoi(delivaryDateLoad.substr(3, 2).c_str()));
	deliveryDate.setYear(atoi(delivaryDateLoad.substr(6).c_str()));
}
