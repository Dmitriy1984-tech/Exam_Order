#include "RegularOrder.h"
#include <string>
#include <fstream>

RegularOrder::RegularOrder():Order()
{
}

RegularOrder::RegularOrder(Date date, Time_ time, string id)
	: Order(date, time, id)
{
}

RegularOrder::~RegularOrder()
{
}

string RegularOrder::type()
{
	return "RegularOrder";
}

string RegularOrder::toString()
{
	return "Issued a regular order number "+id+
		+"\n Order date: "+to_string(date.getDay())+" "+ to_string(date.getMonth())+" "+
		to_string(date.getYear())+"\n Order time: "+
		to_string(time.getHour())+":"+ to_string(time.getMinutes())+":"+
		to_string(time.getSeconds())+"\n\n";
}

void RegularOrder::save(ofstream& file)
{
	file << type() << endl
		<< date << endl
		<< time << endl
		<< id << endl;
		
}

void RegularOrder::load(ifstream& file)
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
}
