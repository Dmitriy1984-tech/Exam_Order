#include "InsureOrder.h"
#include <string>
#include <fstream>

InsureOrder::InsureOrder():Order()
{
   
    this->insurenceCompany = insurenceCompany;
    this->sum = sum;

}

InsureOrder::InsureOrder(Date date, Time_ time, string id, string insurenceCompany, int sum)
    :Order(date, time, id)
{
    
    this->insurenceCompany = insurenceCompany;
    this->sum = sum;
}

InsureOrder::~InsureOrder()
{
}

void InsureOrder::setInsurenceCompany(string insurenceCompany)
{
    this->insurenceCompany = insurenceCompany;
}

string InsureOrder::getInsurenceCompany()
{
    return insurenceCompany;
}

void InsureOrder::setSum(int Sum)
{
    this->sum = sum;
}

int InsureOrder::getSum()
{
    return sum;
}

string InsureOrder::type()
{
    return "InsureOrder";
}

string InsureOrder::toString()
{
    return "Issued a insurence order number " + id +
        +"\n Order date: " + to_string(date.getDay()) + " " + to_string(date.getMonth()) +" "+
        to_string(date.getYear()) + "\n Order time: " +
        to_string(time.getHour()) + ":" + to_string(time.getMinutes()) + ":" +
        to_string(time.getSeconds())
        +"\n insurence company "+ insurenceCompany
        + "\n insurence sum " + to_string(sum)+"\n\n";
}

void InsureOrder::save(ofstream& file)
{
    file << type() << endl
        << date << endl
        << time << endl
        << id << endl
        << insurenceCompany << endl
        << sum << endl;
}

void InsureOrder::load(ifstream& file)
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

    getline(file, insurenceCompany);

    file >> sum;
}



