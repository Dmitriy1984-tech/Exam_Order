#pragma once
#include "Order.h"

class InsureOrder :
    public Order
{
protected:
    string insurenceCompany;
    int sum;

public:
    InsureOrder();
    InsureOrder(Date date, Time_ time, string id,
        string insurenceCompany, int sum);
    ~InsureOrder();

    void setInsurenceCompany(string insurenceCompany);
    string getInsurenceCompany();

    void setSum(int Sum);
    int getSum();

    virtual string type()  override;
    virtual string toString() override;

    virtual void save(ofstream& file) override;
    virtual void load(ifstream& file) override;

    
};

